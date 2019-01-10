//
// Created by bender on 12/18/18.
//

#include "../includes/ft_printf.h"

char *print_number_part_two_d(long long  b, char **str_s)
{
	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		*str_s = ft_itoa(b);
		if (g_cvars.prec) {
			*str_s = prec_helper(*str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		*str_s = ft_itoa((long)b);
		if (g_cvars.prec) {
			*str_s = prec_helper(*str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "z"))) {
		*str_s = ft_itoa(b);
		if (g_cvars.prec) {
			*str_s = prec_helper(*str_s);
		}
		return *str_s;
	}
	return *str_s;
}
char *print_number_part_one_d(long long b, char **str_s)
{
	if (!(ft_strcmp(g_cvars.length, "h"))) {
		*str_s = ft_itoa((short int)b);
		return *str_s;
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		*str_s = ft_itoa((signed char)b);
		return *str_s;
	}
	if (!(ft_strcmp(g_cvars.length, "j"))) {
		*str_s = ft_itoa(b);
		return *str_s;
	}
	return *str_s;
}

void print_number_h(char *str)
{
	int i;

	i = 0;
	while (str[i++] != '-' && str[i]);
	i--;
	if (str[i] == '-' && g_cvars.prec < g_cvars.width && g_cvars.flag[3] != '-') {
		if (g_cvars.flag[2] == '0')
		{
			if (g_cvars.width == (int)ft_strlen(str)) {
				if (g_cvars.flag[3] != '-')
					str[i] = '0';
				str[0] = '-';
			}
		}
	}
	if (g_cvars.flag[0] == ' ') {
		if (g_cvars.flag[1] != '+' && ft_atoi(str) > 0 && g_cvars.symbol != 'u')
			if (g_cvars.prec >= g_cvars.width)
				ft_putchar(' ');
		if (g_cvars.width > g_cvars.prec && ft_atoi(str) >= 0 && g_cvars.flag[2] == '0')
			str[0] = ' ';
	}
	if (g_cvars.flag[1] == '+')
	{
		i = 0;
		if (((g_cvars.width < (int)ft_strlen(str) && g_cvars.symbol != 'u' && g_cvars.symbol != 'p') && ft_atoi(str) >= 0)
		|| ((int)ft_strlen(str) < g_cvars.width && ft_atoi(str) >= 0))
			ft_putchar('+');
		if (g_cvars.width >= (int)ft_strlen(str) && g_cvars.symbol != 'u' && ft_atoi(str) >= 0)
			str[0] = '+';
		if (g_cvars.width > g_cvars.prec && ft_atoi(str) >= 0) {
			if (g_cvars.flag[2] == '0')
				str[0] = '0';
			else
				str[0] = ' ';
			if ((int)ft_strlen(str) == g_cvars.width)
				i++;
			while (str[i++] == ' ');
			str[i - 2] = '+';
		}
	}
	if (g_cvars.flag[3] == '-')
	{
		i  = 0;
		if (g_cvars.prec > g_cvars.width)
		{
			ft_putstr(str);
			return ;
		}
		if (str[i] == '+')
			i++;
		while (str[i] == ' ')
			i++;
		if (ft_atoi(str) < 0 && !g_cvars.width)
			i--;
		if (str[0] == '+')
			ft_putchar('+');
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
	str_s = NULL;

	if (ft_strcmp(g_cvars.length, "\0"))
		number = va_arg(argptr, long long);
	else
		number = va_arg(argptr, int);
	if (ft_strcmp(g_cvars.length, "\0")) {
		str_s = print_number_part_one_d(number, &str_s);
		str_s = print_number_part_two_d(number, &str_s);
	}
	else {
		str_s = ft_itoa(number);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (g_cvars.dot == '.' && g_cvars.prec == 0 && number == 0)
		str_s = "\0";
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
	    ft_putstr(str_s);
	if (ft_strcmp(str_s , "\0"))
		free(str_s);
	clean();
}

