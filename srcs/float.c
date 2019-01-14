/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:57 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 12:03:14 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*float_helper(char *str, double f, int value, int pos)
{
	char	*curr;
	char	len;

	len = pos - 1;
	while (pos < (len + 7))
	{
		f = f - (double)value;
		f *= 10;
		value = (int)f;
		curr = ft_itoa(value);
		str[pos++] = *curr;
		free(curr);
	}
	str[len + 7] = '\0';
	return (str);
}

char	*myfloat(double f)
{
	char			*str;
	unsigned char	pos;
	char			len;
	int				value;

	f += 0.0000005;
	pos = 0;
	value = (int)f;
	str = ft_itoa(value);
	if (f < 0)
	{
		f *= -1;
		value *= -1;
	}
	len = ft_strlen(str);
	pos = len;
	str[pos++] = '.';
	return (float_helper(str, f, value, pos));
}

void	print_number_f(va_list argptr)
{
	char	*str_s;
	int		sign;
	double	yo;

	sign = 1;
	yo = va_arg(argptr, double);
	str_s = myfloat(yo);
	prec_f(sign, str_s);
	if (!(ft_strcmp(g_cvars.length, "L")))
	{
		ft_putstr("nan");
		return ;
	}
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
	clean();
}

void	prec_f_helper(char *str, int j)
{
	if (!g_cvars.prec && g_cvars.dot == '.')
	{
		while (str[j] != '.')
			j++;
		str[j] = '\0';
	}
	if (g_cvars.flag[1] == '+')
		ft_putchar('+');
	if (g_cvars.flag[3] == '-')
	{
		if (ft_atoi(str) >= 0)
			ft_putchar(' ');
		else
			ft_putchar('-');
	}
}

void	prec_f(int sign, char *str)
{
	int		j;
	int		z;
	char	str_w[g_cvars.prec + 1];

	j = 0;
	z = 1;
	if (g_cvars.prec)
	{
		while (str[j] != '.')
			j++;
		while (z <= g_cvars.prec)
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
	prec_f_helper(str, j);
}
