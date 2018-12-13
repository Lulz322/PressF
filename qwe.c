
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";

    ft_printf("%s\n%10.5hd  %1.4hd\n", "This is test string", 121251, 21321321);
    printf("%s\n%10.5hd  %1.4hd\n", "This is test string", 121251, 21321321);

    return (0);
}
void prec(int sign, char *str)
{
	int j;
	int z;
	char str_w[g_cvars.prec + 1];

	if (g_cvars.prec)
	{
		j = 0;
		z = ft_strlen(str);
		if (g_cvars.prec < ft_strlen(str)) {
			if (sign == -1)
				str[0] = '-';
			return;
		}
		z--;
		while (j < g_cvars.prec)
			str_w[j++] = ' ';
		str_w[j] = '\0';
		j--;
		while (str_w[j] && str_w[j] && str[z]){
			str_w[j] = str[z];
			j--;
			z--;
		}
		if (sign == -1)
			str_w[j + 1] = '-';
		ft_putstr(str_w);
	}
}

void prec_helper(char *str, int sign, int b, char *str_s)
{
	int j;
	int z;

	j = 0;
	z = 0;
	if (g_cvars.prec) {
		while (j <= g_cvars.prec) {
			str[j] = '0';
			j++;
		}
		str[j] = '\0';
		while (str_s[z])
			z++;
		z--;
		j--;
		while (str_s[z]) {
			str[j] = str_s[z];
			if (str[j] == '-')
				str[j] = '0';
			j--;
			z--;
		}
	}
}

void width_helper(char *str, int sign, int b, char *str_s)
{
	int j;
	int z;
	char str_w[g_cvars.width + 1];

	if (g_cvars.width)
	{
		j = 0;
		z = ft_strlen(str);
		z--;
		if (g_cvars.width < ft_strlen(str))
		{
			ft_putstr(str);
			return ;
		}
		while (j < g_cvars.width)
			str_w[j++] = ' ';
		str_w[j] = '\0';
		j--;
		while (str_w[j] && str_w[j] && str[z]){
			str_w[j] = str[z];
			j--;
			z--;
		}
		if (sign == -1)
			str_w[j + 1] = '-';
		ft_putstr(str_w);
	}
}