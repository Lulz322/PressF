#include "../includes/ft_printf.h"


t_cvars check_flags(const char *format, va_list argptr)
{

	if (format[i] == ' ' || format[i] == '+' || format[i] == '-' || format[i] == '#' || format[i] == '0')
		g_cvars.flag = format[i++];
	else
		g_cvars.flag = '\0';
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

void check_length(const char *format)
{
	if (format[i] == 'h' && format[i + 1] == 'h') {
		g_cvars.length = "hh";
		i = i+2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		g_cvars.length = "l";
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
	}
	else
		g_cvars.length = "\0";
}

void clean(void)
{
	g_cvars.width = 0;
	g_cvars.length = "\0";
	g_cvars.prec = 0;
	g_cvars.flag = '\0';
}

void print_number(const char *format, va_list argptr) {
	int b;
	unsigned int size;
	char str[g_cvars.prec + 1];
	char *str_s;
	int sign;

	sign = 1;

	b = va_arg(argptr, int);
	if (g_cvars.length == "h") {
		str_s = ft_itoa((short)b);
		if ((short)b < 0)
			sign = -1;
		if (g_cvars.prec)
			prec_helper(str, sign, b, str_s);
	}
	if (g_cvars.prec) {
			prec(sign, str);
	}
	if (g_cvars.width)
			width_helper(str, sign, b, str_s);
	else
		ft_putstr(str);
	clean();
}




void parsing(const char *format, va_list argptr)
{
	if (!(check_symbol(format[++i], argptr)))
		check_cvars(format, argptr);
	if (g_cvars.length == "h" || g_cvars.length == "hh" ||
	g_cvars.length == "l" || g_cvars.length == "ll")
		print_number(format, argptr);

}

void check_cvars(const char *format, va_list argptr)
{
	check_flags(format, argptr);
	check_width(format, argptr);
	if (format[i] == '.')
		check_prec(format);
	check_length(format);


}





int check_symbol(char format, va_list argptr)
{
	if( format == 's' )
	  ft_putstr(va_arg( argptr, char * ));
	else if( format == 'c' )
	  ft_putchar((unsigned char)va_arg( argptr, int ));
	else if( format == 'd' || format == 'i')
	    ft_putnbr(va_arg( argptr, int));
  	else if (format == 'u')
  	    ft_putnbr(va_arg(argptr, unsigned int));
  	else if (format == 'o')
  	    convertDecimalToOctal(va_arg(argptr, unsigned int));
  	else if (format == 'p')
  	    print_address_hex(va_arg(argptr, void *));
	else if (format == '%')
		ft_putchar('%');
	else if (format == 'f' || format == 'F')
        MyFloat(va_arg(argptr, double));
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
}


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
	return (symbols);
}

