//
// Created by bender on 12/9/18.
//

#include "../includes/ft_printf.h"


static int ft_round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

char * MyFloat(double f)
{

	char size = '4';
	char *str;
	char pos;  // position in string
	char len;  // length of decimal part of result
	char* curr;  // temp holder for next digit
	int value;  // decimal digit(s) to convert

	f += 0.0000005;
	pos = 0;  // initialize pos, just to be sure

	value = (int)f;  // truncate the floating point number
	str = ft_itoa(value);  // this is kinda dangerous depending on the length of str
	// now str array has the digits before the decimal

	if (f < 0 )  // handle negative numbers
	{
		f *= -1;
		value *= -1;
	}


	len = ft_strlen(str);  // find out how big the integer part was
	pos = len;  // position the pointer to the end of the integer part
	str[pos++] = '.';  // add decimal point to string

	while(pos < (len + 7) )  // process remaining digits
	{
		f = f - (double)value;  // hack off the whole part of the number
		f *= 10;  // move next digit over
		value = (int)f;  // get next digit
		curr = ft_itoa(value); // convert digit to string
		str[pos++] = *curr; // add digit to result string and increment pointer
	}
	return (str);
}

char * MyGFloat(double f)
{
    char *str;
    int size = 2;
    unsigned char pos;
    char len;
    char* curr;
    int value;

    pos = 0;
	//f += 0.005;
    value = (int)f;
    str = ft_itoa(value);


    if (f < 0 )
    {
        f *= -1;
        value *= -1;
    }

    len = ft_strlen(str);
    pos = len;
    str[pos++] = '.';
    while(pos < (size + len + 1) )
    {
        f = f - (float)value;
        f *= 10;
        curr = ft_itoa(value);
        str[pos++] = *curr;
    }
    pos = 0;
    while(str[pos])
    {
        if (!(ft_isdigit(str[pos])) && str[pos] != '.')
            str[pos] = '\0';
        pos++;
    }
    return (str);

}


void byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
        strcat(b, ((x & z) == z) ? "1" : "0");
    ft_putstr(b);
}

