//
// Created by Ihor RUBAN on 12/21/18.
//

#include "../includes/ft_printf.h"

void print_number_p(va_list argptr)
{
	void *number;
	char *str_s;

	number = va_arg(argptr, void *);
	if (number)
		str_s = print_address_hex(number);
	else
		str_s = ft_strdup("");
	ft_putstr("0x");
	if (!g_cvars.prec && number == 0)
		ft_putchar('0');
	if (g_cvars.prec)
			str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	//print_number_h(str_s);
	if (g_cvars.flag[3] != '-' && number != 0)
		ft_putstr(str_s);
	if (number)
		free(str_s);
	clean();
}
void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

void print_percent(va_list argptr)
{
	char *str_s;
	if (!argptr)
		return;
	str_s = ft_strdup("%\0");
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h_s(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	ft_strdel(&str_s);
	clean();
}

