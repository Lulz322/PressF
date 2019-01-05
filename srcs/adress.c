//
// Created by Ihor RUBAN on 12/21/18.
//

#include "../includes/ft_printf.h"

void print_number_p(va_list argptr)
{
	void *number;
	char *str_s;
	char str[g_cvars.prec + g_cvars.width + 1];
	int sign;

	number = va_arg(argptr, void *);
	if (number)
		str_s = print_address_hex(number);
	else
		str_s = "0x0";
	if (g_cvars.prec)
			str_s = prec_helper(str, str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (number)
		free(str_s);
	clean();
}

void print_percent(va_list argptr)
{
	char *str_s;
	char str[g_cvars.prec + g_cvars.width + 1];

	str_s = "%\0";
	if (g_cvars.prec)
		str_s = prec_helper(str, str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s, 1);
	print_number_h_s(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);

	clean();
}

