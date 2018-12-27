//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_o(unsigned long long b, va_list argptr)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		b = va_arg(argptr, unsigned long long);
		if (g_cvars.symbol == 'o')
			str_s = ft_itoa(convertDecimalToOctal((unsigned long long)b));
		else
			str_s = ft_itoa(b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		b = va_arg(argptr, unsigned long);
		if (g_cvars.symbol == 'o')
			str_s = ft_itoa(convertDecimalToOctal((unsigned long)b));
		else
			str_s = ft_itoa(b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_o(unsigned long long b, va_list argptr)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "h"))) {
		b = va_arg(argptr, unsigned long long);
		if (g_cvars.symbol == 'o')
			str_s = ft_itoa(convertDecimalToOctal((unsigned short)b));
		else
			str_s = ft_itoa(b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		b = va_arg(argptr, unsigned long long);
		if (g_cvars.symbol == 'o')
			str_s = ft_itoa(convertDecimalToOctal((unsigned char)b));
		else
			str_s = ft_itoa(b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	return str_s;
}
void print_number_o(va_list argptr) {
	unsigned long long   number;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	if (!(ft_strcmp(g_cvars.length, "\0"))) {
		number = va_arg(argptr, unsigned int);
		number = convertDecimalToOctal(number);
		str_s = ft_itoa(number);
	}
	else
	{
		str_s = print_number_part_one_o(number, argptr);
		str_s = print_number_part_two_o(number, argptr);
	}
	if (number < 0)
		sign = -1;
	if (g_cvars.prec)
		str_s = prec_helper(str, str_s);
	if (g_cvars.dot == '.' && g_cvars.prec == 0 && number == 0)
		str_s = "\0";
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (g_cvars.width && g_cvars.prec)
		free(str_s);
	clean();
}


void print_number_u(va_list argptr) {
	unsigned long long   number;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	if (!(ft_strcmp(g_cvars.length, "\0"))) {
		number = va_arg(argptr, unsigned int);
		str_s = ft_itoa(number);
	}
	else
	{
		str_s = print_number_part_one_o(number, argptr);
		str_s = print_number_part_two_o(number, argptr);
	}
	if (number < 0)
		sign = -1;
	if (g_cvars.prec)
		str_s = prec_helper(str, str_s);
	if (g_cvars.dot == '.' && g_cvars.prec == 0 && number == 0)
		str_s = "\0";
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (g_cvars.width && g_cvars.prec)
		free(str_s);
	clean();
}