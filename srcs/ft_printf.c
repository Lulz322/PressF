#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../includes/ft_printf.h"



void parsing(const char *format, int i, va_list argptr)
{


	check_symbol(format[++i], argptr);

}




void check_symbol(char format, va_list argptr)
{
	char *s;
	int d;
	char c;

	if( format == 's' )
	  ft_putstr(va_arg( argptr, char * ));
	else if( format == 'c' )
	  ft_putchar((unsigned char)va_arg( argptr, int ));
	// integer
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
}


int ft_printf(const char *format, ...)
{
	int i;

	va_list argptr;

    va_start( argptr, format );
	i = 0;
    while(format[i]) {
	if (format[i] == '%') {
		parsing(format, i, argptr);
		i++;
	}
	else
		ft_putchar(format[i]);
    i++;
    }

    va_end( argptr );
	return (0);
}
