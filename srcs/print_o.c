//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_o(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		str_s = ft_itoa((unsigned long long int)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		str_s = ft_itoa((unsigned long int)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_o(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "h"))) {
		str_s = convertDecimalToOctal((unsigned short int)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		str_s = ft_itoa((unsigned char)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	return str_s;
}
void print_number_o(va_list argptr) {
	unsigned long long int  b;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	b = va_arg(argptr, unsigned int);
	b = convertDecimalToOctal(b);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_o(b, sign);
		str_s = print_number_part_two_o(b, sign);
	}
	else {
		str_s = ft_itoa(b);
		if (b < 0)
			sign = -1;
		if (g_cvars.prec)
			str_s = prec_helper(str, str_s);
	}
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	clean();
}


void print_number_u(va_list argptr) {
	long long  b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	b = va_arg(argptr, unsigned int);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_o(b, sign);
		str_s = print_number_part_two_o(b, sign);
	}
	else {
		str_s = ft_itoa(b);
		if (b < 0)
			sign = -1;
		if (g_cvars.prec)
			str_s = prec_helper(str, str_s);
	}
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	clean();
}