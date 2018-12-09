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
    char pos;  // position in string
    char len;  // length of decimal part of result
    char* curr;  // temp holder for next digit
    int value;  // decimal digit(s) to convert

    pos = 0;  // initialize pos, just to be sure

    value = (int)f;  // truncate the floating point number
    str = ft_itoa(value); // this is kinda dangerous depending on the length of str
    // now str array has the digits before the decimal

    if (f < 0 )  // handle negative numbers
    {
        f *= -1;
        value *= -1;
    }

    len = strlen(str);  // find out how big the integer part was
    pos = len;  // position the pointer to the end of the integer part
    str[pos++] = '.';  // add decimal point to string
    while(pos < (size + len + 1) )  // process remaining digits
    {
        f = f - (float)value;  // hack off the whole part of the number
        f *= 10;  // move next digit ove
        value = (int)(ft_round(f));  // get next digit
        curr = ft_itoa(value); // convert digit to string
        str[pos++] = *curr; // add digit to result string and increment pointer
    }
    ft_putstr(str);

}

