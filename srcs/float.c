//
// Created by bender on 12/9/18.
//

#include "../includes/ft_printf.h"


static int ft_round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

void MyFloat(double f)
{
    char *str;
    int size = 6;
    unsigned char pos;
    char len;
    char* curr;
    int value;

    pos = 0;

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
        value = (ft_round(f));
        curr = ft_itoa(value);
        str[pos++] = *curr;
    }
    ft_putstr(str);

}

void MyGFloat(double f)
{
    char *str;
    int size = 2;
    unsigned char pos;
    char len;
    char* curr;
    int value;

    pos = 0;

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
        value = (int)(ft_round(f));
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
    ft_putstr(str);

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

