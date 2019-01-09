//
// Created by bender on 12/20/18.
//

#include "../includes/ft_printf.h"

void print_string(va_list argptr) {
	char *str_s;
	char *tmp;

	tmp = va_arg(argptr, char *);
	if (tmp == NULL)
		str_s = ft_strdup("(null)");
	else {
		str_s = ft_strdup(tmp);
	}
	if (g_cvars.prec || g_cvars.dot == '.') {
		if (g_cvars.prec < (int)ft_strlen(str_s))
			str_s[g_cvars.prec] = '\0';
	}
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h_s(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	free(str_s);
	clean();
}

void print_number_h_s(char *str)
{
	int i;

	i = 0;
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
	char *str_s;
	char c;


	if (!(str_s = (char *)malloc(sizeof(char) * 2)))
		return;
	c = va_arg(argptr, unsigned int);
	str_s[0] = c;
	str_s[1] = '\0';
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h_s(str_s);
	if (c == '\0')
	{
		str_s[ft_strlen(str_s) - 1] = '\0';
		ft_putstr(str_s);
		ft_putchar(c);
	}
	if (g_cvars.flag[3] != '-' && c != '\0')
		ft_putstr(str_s);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
	clean();
}