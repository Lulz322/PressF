//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_d(long long  b)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		str_s = ft_itoa(b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		str_s = ft_itoa((long)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_d(long long b)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (!(ft_strcmp(g_cvars.length, "h"))) {
		str_s = ft_itoa((short int)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
		return str_s;
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		str_s = ft_itoa((signed char)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
		}
		return str_s;
	}
	return str_s;
}

void print_number_h(char *str)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	if ((ft_atoi(str) > 0 && g_cvars.flag[1] == '+'))
	{
		if (g_cvars.prec > g_cvars.width)
			ft_putstr("+");
		while (str[i++] == ' ');
		str[i - 2] = '+';
	}
	if (g_cvars.flag[3] == '-')
	{
		i  = 0;
		if (g_cvars.prec > g_cvars.width)
		{
			ft_putstr(str);
			return ;
		}
		while (str[++i] == ' ');
		if (ft_atoi(str) < 0 && !g_cvars.width)
			i--;
		while (str[i])
			ft_putchar(str[i++]);
		while (i-- > 0)
			if (str[i] == ' ')
				ft_putchar(str[i]);
	}
}
void print_number(va_list argptr) {
	long long number;
	char *str_s;
	char str[g_cvars.prec + g_cvars.width + 1];
	int sign;


	sign = 1;
	number = va_arg(argptr, int);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_d(number);
		str_s = print_number_part_two_d(number);
	}
	else {
		str_s = ft_itoa(number);
		if (number < 0)
			sign = -1;
		if (g_cvars.prec)
			str_s = prec_helper(str, str_s);
	}
	if (g_cvars.dot == '.' && (g_cvars.prec == 0))
		str_s = "\0";
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
	    ft_putstr(str_s);
	free(str_s);
	clean();
}

