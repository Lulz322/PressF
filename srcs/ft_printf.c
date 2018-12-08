#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"

extern void write_char(char a)
{
    write(1, &a, 1);
}


char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

void print_address_hex(void* p0) {
    int i;
    int counter;
    counter = 1;
    uintptr_t p = (uintptr_t)p0;

    write_char('0'); write_char('x');

    i = (sizeof(p) << 3) - 4;
    while (i >= 0)
    {
        if (counter == 1) {
            while (hex_digit((p >> i) & 0xf) == '0')
                i -= 4;
            counter = 0;
        }
        write_char(hex_digit((p >> i) & 0xf));
        i -= 4;
    }

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
  	    print_address_hex(va_arg(argptr, void *));
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
