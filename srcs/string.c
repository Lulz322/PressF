//
// Created by bender on 12/20/18.
//

#include "../includes/ft_printf.h"

void print_string(va_list argptr) {
	char *b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	unsigned int sign;

	str_s = va_arg(argptr, char *);

	if (g_cvars.prec)
			str_s = prec_helper(str, str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	free(str_s);
	clean();
}

void print_char(va_list argptr) {
	char *b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	unsigned int sign;

	str_s[0] = (unsigned int)va_arg(argptr, int);
	if (g_cvars.prec)
		str_s = prec_helper(str, str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	clean();
}