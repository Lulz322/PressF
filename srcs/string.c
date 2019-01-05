//
// Created by bender on 12/20/18.
//

#include "../includes/ft_printf.h"

void print_string(va_list argptr) {
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	char *tmp;

	tmp = va_arg(argptr, char *);
	if (tmp == NULL)
		str_s = "(null)";
	else {
		str_s = ft_strdup(tmp);
		str_s[ft_strlen(tmp)] = '\0';
	}
	if (g_cvars.prec) {
		if (g_cvars.prec > ft_strlen(str_s))
			str_s = prec_helper(str, str_s);
		else {
			str_s[g_cvars.prec] = '\0';
		}
	}
	if (g_cvars.width)
		str_s = width_helper(str_s, 1);
	print_number_h_s(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (tmp != NULL)
		free(str_s);
	clean();
}

void print_number_h_s(char *str)
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

void print_char(va_list argptr) {
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	unsigned int sign;

	str_s = (char *)malloc(sizeof(char) * 2);
	str_s[0] = (unsigned int)va_arg(argptr, unsigned int);
	str_s[1] = '\0';
	if (str_s[0] == '\0') {
		if (g_cvars.width)
			ft_putchar(' ');
		symbols--;
		str_s = "^@";
	}
	if (g_cvars.prec)
		str_s = prec_helper(str, str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h_s(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	clean();
}