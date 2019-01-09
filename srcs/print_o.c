//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_o(va_list argptr)
{
	char *str_s;

	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		if (g_cvars.symbol == 'u')
			str_s = ft_uitoa(va_arg(argptr, unsigned long long));
		else
			str_s = convertDecimalToOctal(va_arg(argptr, unsigned long long));
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		if (g_cvars.symbol == 'u')
			str_s = ft_uitoa(va_arg(argptr, unsigned  long));
		else
			str_s = convertDecimalToOctal(va_arg(argptr, unsigned  long));
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "z"))) {
		if (g_cvars.symbol == 'u')
			str_s = ft_uitoa((va_arg(argptr, unsigned long long)));
		else
			str_s = convertDecimalToOctal(va_arg(argptr, unsigned long long));
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
		return str_s;
	}
	return str_s;
}
char *print_number_part_one_o(va_list argptr)
{
	char *str_s;

	if (!(ft_strcmp(g_cvars.length, "h"))) {
		if (g_cvars.symbol == 'u')
			str_s = ft_uitoa((unsigned short)va_arg(argptr, unsigned int));
		else
			str_s = convertDecimalToOctal((unsigned short)va_arg(argptr, unsigned int));
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		if (g_cvars.symbol == 'u')
			str_s = ft_uitoa((unsigned char)(va_arg(argptr, unsigned int)));
		else
			str_s = convertDecimalToOctal((unsigned char)va_arg(argptr, unsigned int));
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "j"))) {
		if (g_cvars.symbol == 'u')
			str_s = ft_uitoa((va_arg(argptr, intmax_t)));
		else
			str_s = convertDecimalToOctal(va_arg(argptr, intmax_t));
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
				if (!g_cvars.width && !g_cvars.prec && ft_atoi(str) != 0)
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
	char *tmp;

	b = 0;
	if (!ft_strcmp(g_cvars.length, "\0"))
	{
		b = va_arg(argptr, unsigned int);
		tmp = convertDecimalToOctal(b);
		b = ft_atoi(tmp);
		if (b != 0)
			free(tmp);
		if (g_cvars.dot == '.' && g_cvars.prec == 0 && b == 0)
			str_s = ft_strdup("");
		else
			str_s = ft_itoa(b);

	}
	else
	{
		str_s = print_number_part_one_o(argptr);
		str_s = print_number_part_two_o(argptr);
	}
	if (ft_atoi(str_s) == 0 && g_cvars.width == 0 && g_cvars.prec == 0 && (g_cvars.dot != '.' || g_cvars.flag[4] == '#'))
		str_s = ft_strdup("0\0");
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h_o(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
	clean();
}


void print_number_u(va_list argptr) {
	long long b;
	char *str_s;

	if (!ft_strcmp(g_cvars.length, "\0"))
	{
		b = va_arg(argptr, unsigned int);
		if (g_cvars.dot == '.' && g_cvars.prec == 0 && b == 0)
			str_s = ft_strdup("");
		else
			str_s = ft_itoa(b);
	}
	else
	{
		str_s = print_number_part_one_o(argptr);
		str_s = print_number_part_two_o(argptr);
	}
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s , "\0"))
		free(str_s);
	clean();
}