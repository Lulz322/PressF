#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"




void check_symbol(char format, va_list argptr)
{
	char *s;
	int d;
	char c;

	//string
	if( format == 's' ) {
	  s = va_arg( argptr, char * );
	  ft_putstr(s);
	}
	// character
	else if( format == 'c' ) {
	  c = (char) va_arg( argptr, int );
	  ft_putchar(c);
	}
	// integer
	else if( format == 'd' || format == 'i') {
	  d = va_arg( argptr, int );
	  ft_putnbr(d);
  	}
	else if( format == '%')
		ft_putchar('%');
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
	if (format[i] == '%')
    	check_symbol(format[++i], argptr);
	else
		ft_putchar(format[i]);
    i++;
    }

    va_end( argptr );
	return (0);
}
