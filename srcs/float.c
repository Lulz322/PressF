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
        ft_strcat(b, ((x & z) == z) ? "1" : "0");
    ft_putstr(b);
}


void print_number_f(va_list argptr) {
	char *b;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;
	double yo;

	sign = 1;
	yo = va_arg(argptr, double);
	str_s = MyFloat(yo);
	prec_f(sign, str_s);
	if (!(ft_strcmp(g_cvars.length, "L")))
	{
		ft_putstr("nan");
		return ;
	}
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	clean();
}

void prec_f(int sign, char *str)
{
	int j;
	int z;
	char str_w[g_cvars.prec + 1];

	j = 0;
	z = 1;
	if (g_cvars.prec)
	{
		while(str[j] != '.')
			j++;
		while(z <= g_cvars.prec)
		{
			if (!(ft_isdigit(str[z + j])))
				str[z + j] = '0';
			z++;
		}
		str[z + j] = '\0';
		if (sign == -1)
			str_w[j + 1] = '-';
		if (!(g_cvars.width))
			ft_putstr(str_w);
	}
	if (!g_cvars.prec && g_cvars.dot == '.') {
		while (str[j] != '.')
			j++;
		str[j] = '\0';
	}
	if (g_cvars.flag == '+')
		ft_putchar('+');
	if (g_cvars.flag == '-')
		if(ft_atoi(str) >= 0)
			ft_putchar(' ');
		else
			ft_putchar('-');
}