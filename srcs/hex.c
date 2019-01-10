//
// Created by Ihor RUBAN on 12/8/18.
//

#include "../includes/ft_printf.h"

char *prntnum_lower(uintmax_t num, char sign , uintmax_t base)
{
    int i;
    int j = 0;
    char *outbuf;

	if (ft_strcmp(g_cvars.length, "ll") == 0 || ft_strcmp(g_cvars.length, "l") == 0 ||
	ft_strcmp(g_cvars.length, "j") == 0)
		i = 16;
	else
		i = 12;
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
    while( ++i < 17){
            outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
	if (g_cvars.dot == '.' && g_cvars.prec == 0)
		outbuf = "\0";
    return (outbuf);
}

char * prntnum_upper(long long num, char sign , int base)
{

    int i = 12;
    int j = 0;
    char *outbuf;


	if ((ft_strcmp(g_cvars.length, "ll") == 0 || ft_strcmp(g_cvars.length, "l") == 0 ||
	    ft_strcmp(g_cvars.length, "j") == 0) && num != 4294967296)
		i = 16;
	else
		i = 12;
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
    counter = -13;
    uintptr_t p = (uintptr_t)p0;
    char *str;

	str = (char *)malloc(sizeof(char) * 255);

	i = (sizeof(p) << 3) - 4;
	ft_strcat(str, "0x");
	if (p0 == NULL && g_cvars.dot != '.')
		return (ft_strcat(str, "0"));
	if (p0 == NULL)
		return str;
    while (i >= 0)
    {
        if (counter == -13) {
            while (hex_digit((p >> i) & 0xf) == '0')
                i -= 4;
			counter = 2;
        }
        str[counter++] = hex_digit((p >> i) & 0xf);
        i -= 4;
    }
    return (str);
}

char * convertDecimalToOctal(unsigned long long int  decimalNumber)
{
    unsigned long long  octalNumber = 0;
    unsigned long long i = 1;
    unsigned long long test = 1844674407370955120;

    char *str;

    if (decimalNumber >= test && g_cvars.symbol != 'z')
    	return (ft_strdup("1777777777777777777777"));
	if (decimalNumber >= test && g_cvars.symbol == 'z')
		return (ft_strdup("18446744073709551615"));
    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    str = ft_uitoa(octalNumber);
    return (str);
}
