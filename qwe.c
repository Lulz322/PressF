#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"


int main(void)
{

    char *qwe = "ewoihewro";


	ft_printf("%s %d %c\n%u %o \n%p\n\n", "This is a string", 29, 'X', 124214, 213 , qwe);
	printf("%s %d %c\n%u %o %p\n", "This is a string", 29, 'X', 124214 , 213, qwe);
	return (0);
}
