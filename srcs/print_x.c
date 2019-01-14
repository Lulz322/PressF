/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:19:50 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 15:19:51 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *print_number_part_two_x(unsigned long long sign, char *str_s)
{
	if (!(ft_strcmp(g_cvars.length, "ll"))) {
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower(sign, ' ', 16);
		else
			str_s = prntnum_upper(sign, ' ', 16);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	else if (!(ft_strcmp(g_cvars.length, "l"))) {
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower((unsigned long int)sign, ' ', 16);
		else
			str_s = prntnum_upper((unsigned long int)sign, ' ', 16);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_x(unsigned long long sign, char *str_s)
{
	if (!(ft_strcmp(g_cvars.length, "h"))) {
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower((unsigned short)sign, ' ', 16);
		else
			str_s = prntnum_upper((unsigned short)sign, ' ', 16);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	if (!(ft_strcmp(g_cvars.length, "hh"))) {
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower((unsigned char)sign, ' ', 16);
		else
			str_s = prntnum_upper((unsigned char)sign, ' ', 16);
		if (g_cvars.prec) {
			str_s = prec_helper(str_s);
		}
	}
	return str_s;
}

void print_x_h(char *str)
{
	unsigned int i;
	i = 0;
	if ((ft_atoi(str) > 0 && g_cvars.flag[1] == '+'))
	{
		if (g_cvars.prec > g_cvars.width)
			ft_putstr("+");
		while (str[i++] == ' ');
		str[i - 2] = '+';
	}
	if (g_cvars.flag[4] == '#' && !g_cvars.width && !g_cvars.prec && g_cvars.dot != '.' && g_cvars.symbol == 'X')
		ft_putstr("0X");
	if (g_cvars.flag[4] == '#' && !g_cvars.width && !g_cvars.prec && g_cvars.dot != '.' && g_cvars.symbol == 'x')
		ft_putstr("0x");
	if (g_cvars.flag[4] == '#' && g_cvars.width >= (int)ft_strlen(str) && g_cvars.flag[3] != '-' &&
	!g_cvars.prec && g_cvars.dot != '.')
	{
		i = 2;

		while (str[i] == ' ')
			i++;
		str[i - 2] = '0';
		if (g_cvars.symbol == 'x')
			str[i - 1] = 'x';
		else
			str[i - 1] = 'X';
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
		if (g_cvars.flag[4] == '#')
		{
			str[i - 2] = '0';
			if (g_cvars.symbol == 'x')
				str[i - 1] = 'x';
			else
				str[i - 1] = 'X';
			i = i-2;
		}
		while (str[i])
			ft_putchar(str[i++]);
		while (i-- > 0)
			if (str[i] == ' ')
				ft_putchar(str[i]);
	}
}

char *kostil(char *str_s, long long sign)
{
	if (sign >= 184467440737095516 && g_cvars.symbol == 'X')
		str_s = ft_strdup("FFFFFFFFFFFFFFFF");
	if (sign >= 184467440737095516 && g_cvars.symbol == 'x')
		str_s = ft_strdup("ffffffffffffffff");
	if (sign >= 9223372036854775807 && g_cvars.symbol == 'x')
		str_s = ft_strdup("7fffffffffffffff");
	if (sign >= 9223372036854775807 && g_cvars.symbol == 'X')
		str_s = ft_strdup("7FFFFFFFFFFFFFFF");


	return (str_s);
}


void print_number_x(va_list argptr) {
	char *str_s;
	uintmax_t sign;

	if (!(ft_strcmp(g_cvars.length, "\0")))
		sign = va_arg(argptr, unsigned int);
	else
		sign = va_arg(argptr, unsigned long long);
	if (sign == 0 && !g_cvars.prec && !g_cvars.width && g_cvars.dot != '.') {
		ft_putchar('0');
		return;
	}
	if (g_cvars.dot == '.'&& g_cvars.prec == 0 && g_cvars.width == 0)
		str_s = ft_strdup("\0");
	if (ft_strcmp(g_cvars.length, "\0"))
	{
		str_s = print_number_part_one_x(sign, str_s);
		str_s = print_number_part_two_x(sign, str_s);
		if (!(ft_strcmp(g_cvars.length, "j"))) {
			if (g_cvars.symbol == 'x')
				str_s = prntnum_lower(sign, ' ', 16);
			else
				str_s = prntnum_upper(sign, ' ', 16);
		}
	}
	else {
		sign = (unsigned int)sign;
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower(sign, ' ', 16);
		else
			str_s = prntnum_upper(sign, ' ', 16);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	str_s = kostil(str_s, sign);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_x_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s , "\0"))
		free(str_s);
	clean();
}
