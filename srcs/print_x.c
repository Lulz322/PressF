//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_x(char *b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "ll") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	else if (g_cvars.length == "l") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_x(char *b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "h") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	if (g_cvars.length == "hh") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}

void print_number_x(va_list argptr) {
	char *b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	sign = va_arg(argptr, unsigned int);
	if (g_cvars.symbol == 'x')
		b = prntnum_lower(sign, ' ', 16);
	else
		b = prntnum_upper(sign, ' ', 16);
	if (g_cvars.length) {
		str_s = print_number_part_one_x(b, 1);
		str_s = print_number_part_two_x(b, 1);
	}
	if (g_cvars.width)
		width_helper(str_s, 1);
	clean();
}