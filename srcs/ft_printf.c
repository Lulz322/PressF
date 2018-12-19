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

void check_prec(const char *format)
{
	i++;
	char *str;
	*str = '\0';
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
	else {
		g_cvars.length = "\0";
		return (0);
	}
	return (1);
}

void clean(void)
{
	int i;
	i = 0;
	g_cvars.width = 0;
	g_cvars.length = 0;
	g_cvars.prec = 0;
	while (i++ < 5)
		g_cvars.flag[i] = 0;
	g_cvars.symbol = 0;
	g_cvars.dot = 0;
}


void check_cvars(const char *format, va_list argptr)
{
	check_flags(format, argptr);
	check_width(format, argptr);
	if (format[i] == '.') {
		g_cvars.dot = '.';
		check_prec(format);
	}
	check_length(format);
	check_symbol(format[i]);
}


void parsing(const char *format, va_list argptr)
{
	++i;
	check_cvars(format, argptr);
	if (g_cvars.symbol == 0)
	{
		--i;
		return;
	}
	if (g_cvars.symbol != 'd' && g_cvars.symbol != 's' && g_cvars.symbol != 'o' &&
		g_cvars.symbol != 'u' && g_cvars.symbol != 'i' && g_cvars.symbol != 'c' &&
		g_cvars.symbol != '\0' && g_cvars.symbol != 'p' && g_cvars.symbol != 'x' &&
		g_cvars.symbol != '%' && g_cvars.symbol != 'X' && g_cvars.symbol != 'h' &&
		g_cvars.symbol != 'l' && g_cvars.symbol != 0)
	{
		ft_putchar(g_cvars.symbol);
		clean();
		return;
	}
	if (g_cvars.symbol == 'd')
		print_number( argptr);
	if (g_cvars.symbol == 'o')
		print_number_o(argptr);
	if (g_cvars.symbol == 'u')
		print_number_u(argptr);
	if ((g_cvars.symbol == 'x' || g_cvars.symbol == 'X'))
		print_number_x(argptr);
	if (g_cvars.symbol == 'f')
		print_number_f(argptr);
	if (g_cvars.symbol == '%' && format[i])
		ft_putchar('%');
	if (g_cvars.symbol == 's' )
		ft_putstr(va_arg( argptr, char * ));
	if (g_cvars.symbol == 'c' )
		ft_putchar((unsigned char)va_arg( argptr, int ));
	clean();
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
/*int print_symbol(char format, va_list argptr)
{
	if( format == 's' )
	  ft_putstr(va_arg( argptr, char * ));
	else if( format == 'c' )
	  ft_putchar((unsigned char)va_arg( argptr, int ));
	else if( format == 'd' || format == 'i');
	    //ft_putnbr(va_arg( argptr, int));
  	else if (format == 'u')
  	    ft_putnbr(va_arg(argptr, unsigned int));
  	else if (format == 'o')
  	    convertDecimalToOctal(va_arg(argptr, unsigned int));
  	else if (format == 'p')
  	    print_address_hex(va_arg(argptr, void *));
	else if (format == '%')
		ft_putchar('%');
	else if (format == 'x')
	    prntnum_lower((va_arg(argptr, unsigned int)), ' ' , 16);
	else if (format == 'X')
	    prntnum_upper((va_arg(argptr, unsigned int)), ' ' , 16);
	else if (format == 'b')
	    byte_to_binary(va_arg(argptr, int));
	else if (format == 'k');
	else if (format == 'g')
	    MyGFloat(va_arg(argptr, double));
	else
		return (0);
	return (1);
}*/


int ft_printf(const char *format, ...)
{
	//int i;

	//setlocale("LC_ALL", "");
	va_list argptr;
	symbols = 0;

    va_start( argptr, format );
	i = 0;
    while(format[i]) {
	if (format[i] == '%') {
		parsing(format, argptr);
		//i++;
	}
	else
		ft_putchar(format[i]);
    i++;
    }
    va_end( argptr );
    clean();
	return (symbols);
}

