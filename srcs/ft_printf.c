#include "../includes/ft_printf.h"


t_cvars check_flags(const char *format, va_list argptr) {
	while (format[i] == ' ' || format[i] == '+' || format[i] == '-'
	       || format[i] == '#' || format[i] == '0') {
		if (format[i] == ' ')
			g_cvars.flag[0] = ' ';
		if (format[i] == '+')
			g_cvars.flag[1] = '+';
		if (format[i] == '0')
			g_cvars.flag[2] = '0';
		if (format[i] == '-')
			g_cvars.flag[3] = '-';
		if (format[i] == '#')
			g_cvars.flag[4] = '#';
		i++;
	}
}


void check_width(const char *format, va_list argptr)
{
	//
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
	}
	else
		g_cvars.length = "\0";
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





void print_number_f(va_list argptr) {
	char *b;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;
	double yo;

	sign = 1;
	yo = va_arg(argptr, double);
	str_s = MyFloat(yo);
	prec_f(sign, str_s);
	if (!(ft_strcmp(g_cvars.length, "L")))
	{
		ft_putstr("nan");
		return ;
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	else {
		if (g_cvars.flag == '+')
			ft_putstr(" +");
		if (g_cvars.flag == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
	}
	clean();
}


void parsing(const char *format, va_list argptr)
{
	++i;
	check_cvars(format, argptr);
	if (g_cvars.symbol == '\0')
	{
		ft_putchar('%');
		if (g_cvars.width)
			ft_putnbr(g_cvars.width);
		if (g_cvars.dot)
			ft_putchar(g_cvars.dot);
		if (g_cvars.prec)
			ft_putnbr(g_cvars.prec);
		if (g_cvars.length != "\0")
			ft_putstr(g_cvars.length);
		i--;
		clean();
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
	if (g_cvars.symbol == '%')
		ft_putchar('%');
	if (g_cvars.symbol == 's' )
		ft_putstr(va_arg( argptr, char * ));
	if (g_cvars.symbol == 'c' )
		ft_putchar((unsigned char)va_arg( argptr, int ));




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





int check_symbol(char format)
{
	if( format == 's' )
	  g_cvars.symbol = 's';
	else if( format == 'c' )
	  g_cvars.symbol = 'c';
	else if( format == 'd' || format == 'i')
	    g_cvars.symbol = 'd';
  	else if (format == 'u')
		g_cvars.symbol = 'u';
  	else if (format == 'o')
		g_cvars.symbol = 'o';
  	else if (format == 'p')
		g_cvars.symbol = 'p';
	else if (format == '%')
		g_cvars.symbol = '%';
	else if (format == 'f' || format == 'F')
		g_cvars.symbol = 'f';
	else if (format == 'x')
		g_cvars.symbol = 'x';
	else if (format == 'X')
		g_cvars.symbol = 'X';
	else if (format == 'b')
		g_cvars.symbol = 'b';
	else if (format == 'k')
		g_cvars.symbol = 'k';
	else if (format == 'g')
		g_cvars.symbol = 'g';
	else {
		g_cvars.symbol = '\0';
		return (0);
	}
	return (1);
}
int print_symbol(char format, va_list argptr)
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
    clean();
	return (symbols);
}

