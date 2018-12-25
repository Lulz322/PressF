/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 22:30:46 by bsouchet          #+#    #+#             */
/*   Updated: 2018/11/28 11:23:37 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <locale.h>
#include <inttypes.h>

unsigned int symbols;
int i;

typedef struct s_cvars{
	char dot;
	char flag[5]; // 0 | ' '     1 | +    2 | 0     3 | -  4| #
	char symbol;
	int width;
	char *length;
	int prec;
	int color;
} t_cvars;


t_cvars g_cvars;

enum	e_bool
{
	false = 0,
	true
};

# define _BOOL	typedef enum e_bool	bool


# define _ERR_MSG(msg) ft_putendl(msg)
# define _ERR_NOTIS(ex) if (!(ex)) return ;
# define _ERR_NOTIS_MSG(ex) if (!(ex)) { _ERR_MSG("error"); return (false); }
# define _ERR_NOTIS_O(ex, out) if (!(ex)) return (out)

_BOOL;


/*
** -------------------------- Macros Definition --------------------------------
*/

# define MAX(a, b)		b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)		a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)			(a < 0) ? -a : a
# define DABS(a)		(a < 0.0f) ? -a : a
# define STRERR			strerror

/*
** -------------------------- Colors Definition --------------------------------
*/

# define PF_RED	        "\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[0m"


/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);

/*
** -------------------------- Parsing Functions --------------------------------
*/

int check_symbol(char format);
int print_symbol(char format, va_list argptr);
void parsing(const char *format, va_list argptr);
t_cvars check_flags(const char *format, va_list argptr);
void check_cvars(const char *format, va_list argptr);
void check_width(const char *format, va_list argptr);
void check_prec(const char *format, va_list argptr);
int check_length(const char *format);
char *width_helper(char *str, int sign);
char *prec_helper(char *str, char *str_s);
void clean();

char *print_number_part_two_d(long long int b);
char *print_number_part_one_d(long long int b);
char *print_number_part_two_o(long long b, int sign);
char *print_number_part_one_o(long long b, int sign);
char *print_number_part_two_x(unsigned long long, char *);
char *print_number_part_one_x(unsigned long long, char *);
void print_number(va_list argptr);
void print_number_h(char *str);
void print_x_h(char *str);
void print_string(va_list argptr);
void print_char(va_list argptr);
void print_number_o(va_list argptr);
void print_number_x(va_list argptr);
void print_number_u(va_list argptr);
void print_number_f(va_list argptr);
void print_number_p(va_list argptr);
void print_percent(va_list argptr);
/*
** -------------------------- Numbers Functions --------------------------------
*/

char *                 prntnum_lower(uintmax_t num, char sign , uintmax_t base);
char *                   prntnum_upper(long long num, char sign , int base);
char *                    print_address_hex(void* p0);

char *                   MyFloat(double fVal);
long long int convertDecimalToOctal(unsigned long long int  decimalNumber);
char * MyGFloat(double f);
void byte_to_binary(int x);
void prec_f(int sign, char *str);

//void					itoa_printf(intmax_t d, t_printf *p, int len);
//void					itoa_base_printf(uintmax_t d, int b, t_printf *p);
//void					itoa_base_fill(uintmax_t tmp, int base, char *str,
//						t_printf *p);

/*
** ---------------------- Strings & Chars Functions ----------------------------
*/

//void					pf_putstr(t_printf *p);
//void					pf_putwstr(t_printf *p);
//void					pf_character(t_printf *p, unsigned c);
//void					ft_printf_putstr(char *s, t_printf *p);
//void					pf_putwchar(t_printf *p, unsigned int w, int wl, int n);

/*
** --------------------------- Bonus Functions ---------------------------------
*/

//void					print_pointer_address(t_printf *p);
//void					color(t_printf *p);


/*
** --------------------------- Buffer Functions --------------------------------
*/



#endif
