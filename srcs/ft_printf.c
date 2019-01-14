/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:48:50 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 12:58:04 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	color_help(const char *format)
{
	if (format[i + 1] == 'B' && format[i + 2] == 'L' &&
	format[i + 3] == 'U' && format[i + 4] == '(')
		ft_putstr(PF_BLUE);
	if (format[i + 1] == 'P' && format[i + 2] == 'R' && format[i + 3] == 'P'
	&& format[i + 4] == '(')
		ft_putstr(PF_PURPLE);
	if (format[i + 1] == 'C' && format[i + 2] == 'Y' && format[i + 3] == 'N'
	&& format[i + 4] == '(')
		ft_putstr(PF_CYAN);
}

void	color(const char *format)
{
	if (format[i] == 'M' && format[i + 4] == '(')
	{
		if (format[i + 1] == 'R' && format[i + 2] == 'E' &&
				format[i + 3] == 'D' && format[i + 4] == '(')
			ft_putstr(PF_RED);
		if (format[i + 1] == 'G' && format[i + 2] == 'R' &&
				format[i + 3] == 'N' && format[i + 4] == '(')
			ft_putstr(PF_GREEN);
		if (format[i + 1] == 'Y' && format[i + 2] == 'L' &&
		format[i + 3] == 'W' && format[i + 4] == '(')
			ft_putstr(PF_YELLOW);
		color_help(format);
		i += 5;
		g_cvars.color = 1;
	}
	if (format[i] == ')' && g_cvars.color == 1)
	{
		ft_putstr(PF_EOC);
		if (!format[i + 1])
			exit(symbols);
		i++;
		g_cvars.color = 0;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list argptr;

	symbols = 0;
	i = 0;
	va_start(argptr, format);
	while (format[i])
	{
		color(format);
		if (format[i] == '%')
			parsing(format, argptr);
		else
			ft_putchar(format[i]);
		if (format[i])
			i++;
	}
	va_end(argptr);
	clean();
	return (symbols);
}
