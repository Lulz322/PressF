//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_o(long long b)
{
	char *str_s;

	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		str_s = ft_itoa((unsigned long long )b);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		str_s = ft_itoa((unsigned long )b);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "z"))) {
		str_s = ft_itoa(b);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
		return str_s;
	}
	return str_s;
}
char *print_number_part_one_o(long long b)
{
	char *str_s;

	if (!(ft_strcmp(g_cvars.length, "h"))) {
		str_s = (convertDecimalToOctal((unsigned short int)b));
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		str_s = ft_itoa((unsigned char)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "j"))) {
		str_s = ft_itoa((intmax_t)b);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
		return str_s;
	}
	return str_s;
}

void print_number_h_o(char *str)
{
		int i;
		int counter;

		i = 0;
		counter = 0;
		if (g_cvars.flag[4] == '#')
		{
			if (g_cvars.width > g_cvars.prec) {
				while (str[counter] == ' ' || str[counter] == '0')
					counter++;
				str[counter - 1] = '0';
			}
			else
				if (!g_cvars.width && !g_cvars.prec)
					ft_putchar('0');

		}
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

void print_number_o(va_list argptr) {
	unsigned long long  b;
	char *str_s;

	b = va_arg(argptr, unsigned int);
	b = convertDecimalToOctal(b);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_o(b);
		str_s = print_number_part_two_o(b);
	}
	else {
		if (b != 0)
			str_s = ft_itoa(b);
		else
			str_s = ft_strdup("\0");
		if (b == 0 && g_cvars.width == 0 && g_cvars.prec == 0 && g_cvars.dot != '.')
			str_s = ft_strdup("0\0");
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h_o(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s , "\0"))
		free(str_s);
	clean();
}


void print_number_u(va_list argptr) {
	long long b;
	char *str_s;

	if (ft_strcmp(g_cvars.length, "\0"))
		b = va_arg(argptr, unsigned long long);
	else
		b = va_arg(argptr, unsigned int);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_o(b);
		str_s = print_number_part_two_o(b);
	}
	else {
		str_s = ft_itoa(b);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s , "\0"))
		free(str_s);
	clean();
}