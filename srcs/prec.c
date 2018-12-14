//
// Created by bender on 12/14/18.
//

#include "../includes/ft_printf.h"

void prec(int sign, char *str)
{
	int j;
	int z;
	char str_w[g_cvars.prec + 1];

	if (g_cvars.prec)
	{
		j = 0;
		z = ft_strlen(str);
		z--;
		while (j < g_cvars.prec)
			str_w[j++] = ' ';
		str_w[j] = '\0';
		j--;
		while (str_w[j] && str_w[j] && str[z]){
			str_w[j] = str[z];
			j--;
			z--;
		}
		if (sign == -1)
			str_w[j + 1] = '-';
		if (!(g_cvars.width))
			ft_putstr(str_w);
	}
}
void prec_f(int sign, char *str)
{
	int j;
	int z;
	char str_w[g_cvars.prec + 1];

	j = 0;
	z = 1;
	if (g_cvars.prec)
	{
		while(str[j] != '.')
			j++;
		while(z <= g_cvars.prec)
		{
			if (!(ft_isdigit(str[z + j])))
				str[z + j] = '0';
			z++;
		}
		str[z + j] = '\0';
		if (sign == -1)
			str_w[j + 1] = '-';
		if (!(g_cvars.width))
			ft_putstr(str_w);
	}
	if (!g_cvars.prec && g_cvars.dot == '.') {
		while (str[j] != '.')
			j++;
		str[j] = '\0';
	}
}

char *prec_helper(char *str, char *str_s)
{
	int j;
	int z;

	j = 0;
	z = 0;
	if (g_cvars.prec) {
		if (g_cvars.prec < len(ft_atoi(str_s)))
		{
			while (j < len(ft_atoi(str_s)))
			{
				str[j] = '0';
				j++;
			}
		}
		else {
			while (j < g_cvars.prec) {
				str[j] = '0';
				j++;
			}
		}
		str[j] = '\0';
		while (str_s[z])
			z++;
		z--;
		j--;
		while (str_s[z]) {
			str[j] = str_s[z];
			if (str[j] == '-')
				str[j] = '0';
			j--;
			z--;
		}
	}
	return (str);
}

void width_helper(char *str, int sign)
{
	int j;
	int z;
	char str_w[g_cvars.width + 1];

	if (g_cvars.width)
	{
		j = 0;
		z = ft_strlen(str);
		z--;
		if (g_cvars.width < ft_strlen(str))
		{
			ft_putstr(str);
			return ;
		}

		while (j < g_cvars.width) {
			if (g_cvars.flag == '0')
				str_w[j++] = '0';
			else
				str_w[j++] = ' ';
		}

		str_w[j] = '\0';
		j--;
		while (str_w[j] && str_w[j] && str[z]){
			str_w[j] = str[z];
			j--;
			z--;
		}
		if (sign == -1)
			str_w[j + 1] = '-';
		ft_putstr(str_w);
	}
}