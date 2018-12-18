//
// Created by bender on 12/14/18.
//

#include "../includes/ft_printf.h"

void prec(int sign, char *str)
{
	int j;
	int z;
	char str_w[g_cvars.prec + 1];

	if (ft_atoi(str) < 0)
		sign = -1;

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
		if (!(g_cvars.width)) {
			if (g_cvars.flag[3] == '-' && sign != -1)
				ft_putchar('-');
			if (g_cvars.flag[3] == '+' && sign != 1)
				ft_putchar('+');
			ft_putstr(str_w);
		}
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
	if (g_cvars.flag == '+')
		ft_putchar('+');
	if (g_cvars.flag == '-')
		if(ft_atoi(str) >= 0)
			ft_putchar(' ');
	else
		ft_putchar('-');
}


char *prec_helper(char *str, char *str_s)
{
	int j;
	int z;

	j = 0;
	z = 0;
	if (g_cvars.prec) {
			if (g_cvars.flag[1] || g_cvars.flag[3])
				g_cvars.prec++;
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
		return (str);
	}
	return (str_s);
}

void width_helper(char *str, int sign)
{
	int j;
	int z;
	char str_w[g_cvars.width + 1];


	if (ft_atoi(str) < 0)
		sign = -1;
	if (g_cvars.width) {
		j = 0;
		z = ft_strlen(str);
		z--;
		if (g_cvars.width < ft_strlen(str)) {
			ft_putstr(str);
			return;
		}
			//if (g_cvars.flag[1] || g_cvars.flag[3])
			//	g_cvars.width++;
		while (j < g_cvars.width) {
			if (g_cvars.flag[2] == '0')
				str_w[j++] = '0';
			else
				str_w[j++] = ' ';
		}
		str_w[j] = '\0';
		j--;
		if (g_cvars.flag[3] != '-') {
			while (str_w[j] && str[z]) {
				if (g_cvars.flag[1] == '+')
					if (str[z] == str[0] && !str[z - 1])
						str_w[j - 1] = '+';
				str_w[j] = str[z];
				j--;
				z--;
			}
		}
		else
		{
			j = 1;
			z = 0;
			if (g_cvars.flag[1] == '+' && sign != -1)
				str_w[0] = '+';
			if (g_cvars.flag[3] == '-' && sign == -1)
				str_w[0] = '-';
			if (sign == -1)
				z++;
			while (j < g_cvars.width)
			{
				if (str[z] && str_w[j])
					str_w[j] = str[z];
				z++;
				j++;
			}
		}

		ft_putstr(str_w);
	}
}