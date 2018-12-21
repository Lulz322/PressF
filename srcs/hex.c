//
// Created by Ihor RUBAN on 12/8/18.
//

#include "../includes/ft_printf.h"

char *prntnum_lower(long long num, char sign , int base)
{
    int i = 12;
    int j = 0;
    char *outbuf;

    outbuf = ft_strnew(sizeof(char) * 255);
    do{
        outbuf[i] = "0123456789abcdef"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }
	if (g_cvars.flag[4] == '#' && g_cvars.flag[1] != '+')
	{
		outbuf[j] = '0';
		outbuf[j + 1] = 'x';
		j += 2;
	}
    while( ++i < 13){
        outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
    return (outbuf);

}

char * prntnum_upper(unsigned int num, char sign , int base)
{

    int i = 12;
    int j = 0;
    char *outbuf;
    outbuf = ft_strnew(sizeof(char) * 255);
    do{
        outbuf[i] = "0123456789ABCDEF"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }
    if (g_cvars.flag[4] == '#')
    {
        outbuf[j] = '0';
        outbuf[j + 1] = 'X';
        j += 2;
    }
    while( ++i < 13){
        outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
    return (outbuf);

}

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

char *print_address_hex(void* p0) {
    int i;
    int counter;
    counter = 1;
    uintptr_t p = (uintptr_t)p0;
    char *str;

	str = (char *)malloc(sizeof(char) * 255);

	str[0] = '0';
	str[1] = 'x';
    i = (sizeof(p) << 3) - 4;
    while (i >= 0)
    {
        if (counter == 1) {
            while (hex_digit((p >> i) & 0xf) == '0')
                i -= 4;
            counter = 2;
        }
        str[counter++] = hex_digit((p >> i) & 0xf);
        i -= 4;
    }
    return (str);
}

long long int convertDecimalToOctal(unsigned long long int  decimalNumber)
{
    long long int octalNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}
