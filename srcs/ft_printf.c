#include "../includes/ft_printf.h"


t_cvars check_flags(const char *format, va_list argptr)
{

	if (format[i] == ' ' || format[i] == '+' || format[i] == '-' || format[i] == '#' || format[i] == '0')
		g_cvars.flag = format[i++];
	else
		g_cvars.flag = '\0';
}

void check_width(const char *format, va_list argptr)
{
	char *str;
	*str = '\0';
	int j;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
		str[j++] = format[i++];
	str[j] = '\0';
	g_cvars.width = ft_atoi(str);
}

void check_prec(const char *format)
{
	i++;
	char *str;
	*str = '\0';
	int j;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
		str[j++] = format[i++];
	str[j] = '\0';
	g_cvars.prec = ft_atoi(str);

}

void check_length(const char *format)
{
	if (format[i] == 'h' && format[i + 1] == 'h') {
		g_cvars.length = "hh";
		i = i+2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		g_cvars.length = "l";
		i = i + 2;
	}
	else if (format[i] == 'h') {

		i++;
		g_cvars.length = "h";
	}
	else if (format[i] == 'l') {
		g_cvars.length = "l";
		i++;
	}
	else if (format[i] == 'L')
	{
		g_cvars.length = "L";
				i++;
	}
	else
		g_cvars.length = "\0";
}

void clean(void)
{
	g_cvars.width = 0;
	g_cvars.length = "\0";
	g_cvars.prec = 0;
	g_cvars.flag = '\0';
	g_cvars.symbol = '\0';
	g_cvars.dot = '\0';
}

char *print_number_part_two_d(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "ll") {
		str_s = ft_itoa((long long int)b);
		if ((long long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	else if (g_cvars.length == "l") {
		str_s = ft_itoa((long int)b);
		if ((long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_d(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "h") {
		str_s = ft_itoa((short int)b);
		if ((short int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	if (g_cvars.length == "hh") {
		str_s = ft_itoa((signed char)b);
		if ((signed char)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}


void print_number(va_list argptr) {
	long long  b;
	char *str_s;
	char str[g_cvars.prec + g_cvars.width + 1];
	int sign;

	sign = 1;
	b = va_arg(argptr, int);


	if (!(g_cvars.length == "\0")) {
		str_s = print_number_part_one_d(b, sign);
		str_s = print_number_part_two_d(b, sign);
	}
	else {
		str_s = prec_helper(str, ft_itoa(b));
		prec(sign, str_s);
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	else {
		if (g_cvars.flag == '+')
			ft_putstr(" +");
		if (g_cvars.flag == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
		//free(str_s);
	}

	clean();
}

char *print_number_part_two_o(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "ll") {
		str_s = ft_itoa((unsigned long long int)b);
		if ((long long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	else if (g_cvars.length == "l") {
		str_s = ft_itoa((unsigned long int)b);
		if ((long int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_o(long long b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "h") {
		str_s = ft_itoa((unsigned short int)b);
		if ((unsigned short int)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	if (g_cvars.length == "hh") {
		str_s = ft_itoa((unsigned char)b);
		if ((unsigned char)b < 0)
			sign = -1;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
void print_number_o(va_list argptr) {
	long long  b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	b = va_arg(argptr, unsigned int);
	b = convertDecimalToOctal(b);
	if (!(g_cvars.length == "\0")) {
		str_s = print_number_part_one_o(b, sign);
		str_s = print_number_part_two_o(b, sign);
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	else {
		if (g_cvars.flag == '+')
			ft_putstr(" +");
		if (g_cvars.flag == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
	}
	clean();
}

char *print_number_part_two_x(char *b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (strcmp(g_cvars.length, "ll")) {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	else if (g_cvars.length == "l") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}
char *print_number_part_one_x(char *b, int sign)
{
	char *str_s;
	char *str[g_cvars.width + g_cvars.prec + 1];

	if (g_cvars.length == "h") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	if (g_cvars.length == "hh") {
		str_s = b;
		if (g_cvars.prec) {
			str_s = prec_helper(str,str_s);
			prec(sign, str_s);
		}
	}
	return str_s;
}

void print_number_x(va_list argptr) {
	char *b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	long long sign;

	sign = 1;
	sign = va_arg(argptr, unsigned int);
	if (g_cvars.symbol == 'x')
		b = prntnum_lower(sign, ' ', 16);
	else
		b = prntnum_upper(sign, ' ', 16);
	if (!(g_cvars.length == "\0")) {
		str_s = print_number_part_one_x(b, sign);
		str_s = print_number_part_two_x(b, sign);
	}
	else {
		str_s = prec_helper(str, b);
		prec(sign, str_s);
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	else {
		if (g_cvars.flag == '+')
			ft_putstr(" +");
		if (g_cvars.flag == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag == '#')
			ft_putstr("0x");
		ft_putstr(str_s);
		//free(str_s);
	}

	clean();
}

void print_number_u(va_list argptr) {
	long long  b;
	unsigned int size;
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	int sign;

	sign = 1;
	b = va_arg(argptr, unsigned int);
	if (!(g_cvars.length == "\0")) {
		str_s = print_number_part_one_o(b, sign);
		str_s = print_number_part_two_o(b, sign);
	}
	else {
		str_s = prec_helper(str, ft_itoa(b));
		prec(sign, str_s);
	}
	if (g_cvars.width)
		width_helper(str_s, sign);
	else {
		if (g_cvars.flag == '+')
			ft_putstr(" +");
		if (g_cvars.flag == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
		//free(str_s);
	}

	clean();
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
	if (g_cvars.width)
		width_helper(str_s, sign);
	else {
		if (g_cvars.flag == '+')
			ft_putstr(" +");
		if (g_cvars.flag == '-')
			if (ft_atoi(str_s) >= 0)
				ft_putchar(' ');
		if (g_cvars.flag == '#')
			ft_putchar(' ');
		ft_putstr(str_s);
	}
	clean();
}


void parsing(const char *format, va_list argptr)
{
	++i;
	check_cvars(format, argptr);
	if (g_cvars.width > 300)
		exit(-0);
	if (g_cvars.symbol == 'd' || g_cvars.symbol == 'i')
		print_number( argptr);
	else if (g_cvars.symbol == 'o')
		print_number_o(argptr);
	else if (g_cvars.symbol == 'u')
		print_number_u(argptr);
	else if (g_cvars.symbol == 'x' || g_cvars.symbol == 'X')
		print_number_x(argptr);
	else if (g_cvars.symbol == 'f')
		print_number_f(argptr);
	else if (g_cvars.symbol == 's')
		ft_putstr(va_arg( argptr, char * ));
	else if (g_cvars.symbol == 'c')
		ft_putchar((unsigned char)va_arg( argptr, int ));
	else
	{
		if (g_cvars.symbol)
			ft_putchar(g_cvars.symbol);
		if (g_cvars.width)
			ft_putnbr(g_cvars.width);
		if (g_cvars.dot)
			ft_putchar(g_cvars.dot);
		if (g_cvars.prec)
			ft_putnbr(g_cvars.prec);
		if (g_cvars.length != "\0")
			ft_putstr(g_cvars.length);
		i--;
		clean();
	}





}

void check_cvars(const char *format, va_list argptr)
{
	check_flags(format, argptr);
	check_width(format, argptr);
	if (format[i] == '.') {
		g_cvars.dot = '.';
		check_prec(format);
	}
	check_length(format);
	check_symbol(format[i]);
}





int check_symbol(char format)
{
	if (format != '\0' && format != ' ')
		g_cvars.symbol = format;
	else {
		g_cvars.symbol = '\0';
		return (0);
	}
	return (1);
}

int ft_printf(const char *format, ...)
{
	//int i;

	//setlocale("LC_ALL", "");
	va_list argptr;
	symbols = 0;

    va_start( argptr, format );
	i = 0;
    while(format[i]) {
	if (format[i] == '%') {
		parsing(format, argptr);
	}
	else
		ft_putchar(format[i]);
    i++;
    }
    va_end( argptr );
	return (symbols);
}

