#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"

void check_symbol(char format, va_list argptr)
{
	//string
	if( format == 's' ) {
	  char* s = va_arg( argptr, char * );
	  ft_putstr(s);
	 // ft_putchar('\n');
	}
	// character
	else if( format == 'c' ) {
	  char c = (char) va_arg( argptr, int );
	  ft_putchar(c);
	 // ft_putchar('\n');
	}
	// integer
	else if( format == 'd' ) {
	  int d = va_arg( argptr, int );
	  ft_putnbr(d);
	  //ft_putchar('\n');
  	}
	else if( format == '%')
		ft_putchar('%');
	else if (format == 'n')
		ft_putchar('\n');
	else if (format == '\\')
		ft_putstr("\\");
	else if (format == '\t')
		ft_putchar('\t');
	else if (format == '\a')
		ft_putchar('\a');
}

int ft_printf(const char *format, ...)
{
	int i;

	va_list argptr;

    va_start( argptr, format );
	i = 0;
    while(format[i]) {
	if (format[i] == '%' || format[i] == '\\')
    	check_symbol(format[++i], argptr);
	else
		ft_putchar(format[i]);
    i++;
    }

    va_end( argptr );
	return (0);
}
