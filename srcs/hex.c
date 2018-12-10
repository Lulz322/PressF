//
// Created by Ihor RUBAN on 12/8/18.
//

#include "../includes/ft_printf.h"

void prntnum_lower(unsigned int num, char sign , int base)
{

    int i = 12;
    int j = 0;
    char outbuf[255];

    do{
        outbuf[i] = "0123456789abcdef"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }

    while( ++i < 13){
        outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
    ft_putstr(outbuf);

}

void prntnum_upper(unsigned int num, char sign , int base)
{

    int i = 12;
    int j = 0;
    char outbuf[255];

    do{
        outbuf[i] = "0123456789ABCDEF"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }

    while( ++i < 13){
        outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
    ft_putstr(outbuf);

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

    ft_putchar('0');
    ft_putchar('x');

    i = (sizeof(p) << 3) - 4;
    while (i >= 0)
    {
        if (counter == 1) {
            while (hex_digit((p >> i) & 0xf) == '0')
                i -= 4;
            counter = 0;
        }
        ft_putchar(hex_digit((p >> i) & 0xf));
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
