#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"


void putstramper(void *str)
{
    unsigned char *a = &str;
    ft_putstr(a);
}


void convertDecimalToOctal(unsigned int  decimalNumber)
{
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    ft_putnbr(octalNumber);
}


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
	else if( format == 'd' || format == 'i')
	    ft_putnbr(va_arg( argptr, int));
  	else if (format == 'u')
  	    ft_putnbr(va_arg(argptr, unsigned int));
  	else if (format == 'o')
  	    convertDecimalToOctal(va_arg(argptr, unsigned int));
  	else if (format == 'p')
  	    putstramper(va_arg(argptr, void *));
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
