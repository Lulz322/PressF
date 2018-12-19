//
// Created by bender on 12/14/18.
//

#include "../includes/ft_printf.h"



char *prec_helper(char *str, char *str_s)
{
	int j;
	int z;

	j = 0;
	z = 0;

	if (len(ft_atoi(str_s)) > g_cvars.prec)
	{
		str = (char *) malloc(sizeof(char) * len(ft_atoi(str_s)) + 1);
		while (j < len(ft_atoi(str_s)))
			str[j++] = '0';
	}
	else
		{
		if (ft_atoi(str_s) < 0)
			g_cvars.prec++;
		str = (char *) malloc(sizeof(char) * g_cvars.prec + 1);
		while (j < g_cvars.prec)
			str[j++] = '0';
	}
	str[j] = '\0';
	while (str_s[z])
		z++;
	z--;
	j--;
	while (str_s[z]) {
		str[j--] = str_s[z--];
		if (str[j + 1] == '-')
			str[j + 1] = '0';
	}
	if (ft_atoi(str_s) < 0)
		str[0] = '-';
	return (str);
}

char *width_helper(char *str, int sign)
{
	int j;
	int z;
	char *str_w;

	str_w = (char *)malloc((sizeof(char) * g_cvars.width + 1));
	j = 0;
	z = ft_strlen(str);
	z--;
	if (g_cvars.prec > g_cvars.width || len(ft_atoi(str)) > g_cvars.width)
		return (str);
	if (((g_cvars.prec > g_cvars.width ) && ft_atoi(str) < 0 ))
		g_cvars.width--;
	while (j < g_cvars.width ) {
			str_w[j++] = ' ';
	}
	str_w[j] = '\0';
	j--;
	while (str[z] && str_w[j])
			str_w[j--] = str[z--];
	return (str_w);
}