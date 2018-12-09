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

# define PF_RED			"\033[31m"
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

void check_symbol(char format, va_list argptr);
void parsing(const char *format, int i, va_list argptr);

/*
** -------------------------- Numbers Functions --------------------------------
*/

void                    prntnum_lower(unsigned int num, char sign , int base);
void                    prntnum_upper(unsigned int num, char sign , int base);
void                    print_address_hex(void* p0);

void                    MyFloat(double fVal);
void convertDecimalToOctal(unsigned int  decimalNumber);

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
