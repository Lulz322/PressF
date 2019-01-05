#include "../includes/ft_printf.h"



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


void color(const char *format) {
	if (format[i] == 'M' && format[i + 4] == '(') {
		if (format[i + 1] == 'R' && format[i + 2] == 'E' &&
		    format[i + 3] == 'D' &&
		    format[i + 4] == '(' )
			ft_putstr(PF_RED);
		if (format[i + 1] == 'G' && format[i + 2] == 'R' &&
		    format[i + 3] == 'N' &&
		    format[i + 4] == '(' )
			ft_putstr(PF_GREEN);
		if (format[i + 1] == 'Y' && format[i + 2] == 'L' &&
		    format[i + 3] == 'W' &&
		    format[i + 4] == '(' )
			ft_putstr(PF_YELLOW);
		if (format[i + 1] == 'B' && format[i + 2] == 'L' &&
		    format[i + 3] == 'U' &&
		    format[i + 4] == '(' )
			ft_putstr(PF_BLUE);
		if (format[i + 1] == 'P' && format[i + 2] == 'R' &&
		    format[i + 3] == 'P' &&
		    format[i + 4] == '(' )
			ft_putstr(PF_PURPLE);
		if (format[i + 1] == 'C' && format[i + 2] == 'Y' &&
		    format[i + 3] == 'N' &&
		    format[i + 4] == '(' )
			ft_putstr(PF_CYAN);
		i += 5;
		g_cvars.color = 1;
	}
	if (format[i] == ')' && g_cvars.color == 1) {
		ft_putstr(PF_EOC);
		if (!format[i + 1])
			exit(symbols);
		i++;
		g_cvars.color = 0;
	}
}

int ft_printf(const char *format, ...)
{
	va_list argptr;
	va_list test;
	int j;
	j = i;
	symbols = 0;
	i = 0;
    va_start (argptr, format );
    while(format[i]) {
    	color(format);
		if (format[i] == '%' ){
			parsing(format, argptr);
		}
		else {
			ft_putchar(format[i]);
		}
		if (format[i])
            i++;
    }
    va_end(argptr);
    clean();
	i = j;
	return (symbols);
}

