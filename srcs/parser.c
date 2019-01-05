//
// Created by bender on 12/19/18.
//

#include "../includes/ft_printf.h"


void clean(void)
{
	int j;

	j = 0;
	g_cvars.width = 0;
	g_cvars.length = 0;
	g_cvars.prec = 0;
	while (j++ < 5)
		g_cvars.flag[j] = 0;
	g_cvars.symbol = 0;
	g_cvars.dot = 0;
}

void parsing(const char *format, va_list argptr)
{
	++i;
	check_cvars(format, argptr);
	if (g_cvars.symbol == 0)
	{
		if (format[i] != '\0')
			--i;
		return;
	}

	if (g_cvars.symbol != 'd' && g_cvars.symbol != 's' && g_cvars.symbol != 'o' &&
	    g_cvars.symbol != 'u' && g_cvars.symbol != 'i' && g_cvars.symbol != 'c' &&
	    g_cvars.symbol != '\0' && g_cvars.symbol != 'p' && g_cvars.symbol != 'x' &&
	    g_cvars.symbol != '%' && g_cvars.symbol != 'X' &&
	    g_cvars.symbol != 0 && g_cvars.symbol != 'f')

	{
		ft_putchar(g_cvars.symbol);

		clean();
		return;
	}
	if (g_cvars.symbol == 'd' || g_cvars.symbol == 'i' ||
	g_cvars.symbol == 'D' || g_cvars.symbol == 'I')
		print_number(argptr);
	if (g_cvars.symbol == 'o')
		print_number_o(argptr);
	if (g_cvars.symbol == 'u')
		print_number_u(argptr);
	if ((g_cvars.symbol == 'x' || g_cvars.symbol == 'X'))
		print_number_x(argptr);
	if (g_cvars.symbol == 'f')
		print_number_f(argptr);
	if (g_cvars.symbol == '%' && format[i])
		print_percent(argptr);
	if (g_cvars.symbol == 's')
		print_string(argptr);
	if (g_cvars.symbol == 'c')
		print_char(argptr);
	if (g_cvars.symbol == 'p')
		print_number_p(argptr);
	clean();
}