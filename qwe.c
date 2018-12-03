#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"


int main(void)
{
	ft_printf( "%s %d %c\n %% \\ / \a\n", "This is a string", 29, 'X' );
	printf( "%s %d %c\n %% \\ / \a\n", "This is a string", 29, 'X' );
	return (0);
}
