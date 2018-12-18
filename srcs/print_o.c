//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_o(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "ll") {
		str_s = ft_itoa((unsigned long long int)b);
		if ((long long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	else if (g_cvars.length == "l") {
		str_s = ft_itoa((unsigned long int)b);
		if ((long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_o(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "h") {
		str_s = ft_itoa((unsigned short int)b);
		if ((unsigned short int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	if (g_cvars.length == "hh") {
		str_s = ft_itoa((unsigned char)b);
		if ((unsigned char)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
void print_number_o(va_list argptr) {
	long long  b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	b = va_arg(argptr, unsigned int);
	b = convertDecimalToOctal(b);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_d(b, sign);
		str_s = print_number_part_two_d(b, sign);
	}
	else {

		str_s = prec_helper(str, ft_itoa(b));
		prec(sign, str_s);
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	if (!g_cvars.width && !g_cvars.prec)
	{
		if (g_cvars.flag[1] == '+')
			ft_putstr(" +");
		if (g_cvars.flag[3] == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag[4] == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
	}

	clean();
}

//
void print_number_u(va_list argptr) {
	long long  b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	b = va_arg(argptr, unsigned int);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_d(b, sign);
		str_s = print_number_part_two_d(b, sign);
	}
	else {

		str_s = prec_helper(str, ft_itoa(b));
		prec(sign, str_s);
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	if (!g_cvars.width && !g_cvars.prec)
	{
		if (g_cvars.flag[1] == '+')
			ft_putstr(" +");
		if (g_cvars.flag[3] == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag[4] == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
	}

	clean();
}