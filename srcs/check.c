//
// Created by bender on 12/19/18.
//

#include "../includes/ft_printf.h"

t_cvars check_flags(const char *format, va_list argptr) {
	while (format[i] == ' ' || format[i] == '+' || format[i] == '-'
	       || format[i] == '#' || format[i] == '0') {
		if (format[i] == ' ')
			g_cvars.flag[0] = ' ';
		else if (format[i] == '+')
			g_cvars.flag[1] = '+';
		else if (format[i] == '0')
			g_cvars.flag[2] = '0';
		else if (format[i] == '-')
			g_cvars.flag[3] = '-';
		else if (format[i] == '#')
			g_cvars.flag[4] = '#';
		i++;
	}
}


void check_width(const char *format, va_list argptr)
{
	char *str;
	*str = '\0';
	int j;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
		str[j++] = format[i++];
	str[j] = '\0';
	g_cvars.width = ft_atoi(str);
}

void check_prec(const char *format, va_list argptr)
{
	char str[13];
	str[0] = '\0';
	int j;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
		str[j++] = format[i++];
	str[j] = '\0';
	g_cvars.prec = ft_atoi(str);

}

int check_length(const char *format)
{
	if (format[i] == 'h' && format[i + 1] == 'h') {
		g_cvars.length = "hh";
		i = i+2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		g_cvars.length = "ll";
		i = i + 2;
	}
	else if (format[i] == 'h') {

		i++;
		g_cvars.length = "h";
	}
	else if (format[i] == 'l') {
		g_cvars.length = "l";
		i++;
	}
	else if (format[i] == 'L')
	{
		g_cvars.length = "L";
		i++;
		return (1);
	}
	else if (format[i] == 'j')
	{
		g_cvars.length = "j";
		i++;
		return (1);
	}
	else if (format[i] == 'z') {
		g_cvars.length = "z";
		i++;
		return (1);
	}
	else if (format[i] == 't') {
		g_cvars.length = "t";
		i++;
		return (1);
	}

	else {
		g_cvars.length = "\0";
		return (0);
	}
	return (1);
}

void check_cvars(const char *format, va_list argptr)
{
	if (format[i - 1] == '%' && ((format[i] == ' ' && format[i + 1] == '\0') ||
	format[i] == '\0')) {
		++i;
		return;
	}
	check_flags(format, argptr);
	check_width(format, argptr);
	if (format[i] == '.')
	{
		while (format[++i] == '.');
		g_cvars.dot = '.';
	}
	if (g_cvars.dot == '.')
		check_prec(format, argptr);
	check_length(format);
	while ((format[i] && ((format[i] != '%' && format[i] != 'x'
	&& format[i] != 'd' && format[i] != 'o' && format[i] != 'i'
	&& format[i] != 'f' && format[i] != 'b' && format[i] != 'X'
	&& format[i] != 'u' && format[i] != 's' && format[i] != 'c'
	&& format[i] != ' '))))
		i++;
	if (format[i] == '\0') {
		while (!ft_isalpha(format[i--]));
	}
	check_symbol(format[i]);

}


int check_symbol(char format)
{
	if (format)
		g_cvars.symbol = format;
	else{
		g_cvars.symbol = 0;
		return (0);
	}
	return (1);
}