//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_d(long long  b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		str_s = ft_itoa(b);
		if (b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		str_s = ft_itoa((long)b);
		if ((long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_d(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "h"))) {
		str_s = ft_itoa((short int)b);
		if ((short int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		str_s = ft_itoa((signed char)b);
		if ((signed char)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}


void print_number(va_list argptr) {
	long long int b;
	char *str_s;
	char str[g_cvars.prec + g_cvars.width + 1];
	int sign;

	sign = 1;
	b = va_arg(argptr, int);

	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_d(b, sign);
		str_s = print_number_part_two_d(b, sign);
	}
	else {
		if (b < 0)
			sign = -1;
		str_s = prec_helper(str, ft_itoa(b));
		prec(sign, str_s);
	}
	if (b < 0)
		sign = -1;
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

void print_procent(void)
{
	long long int b;
	char *str_s;
	char str[g_cvars.prec + g_cvars.width + 1];
	int sign;

	sign = 1;
	b = 2;

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
		ft_putstr("%");
	}

	clean();
}