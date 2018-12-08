#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";

	ft_printf("%s %d %c\n%u %o %p\n\n", "This is a string", 29, 'X', 124214, 213 , qwe);
	printf("\n%s %d %c\n%u %o %p\n%5d\n", "This is a string", 29, 'X', 124214 , 213, qwe, 12345);
	return (0);
}
