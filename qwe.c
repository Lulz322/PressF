#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"


int main(void)
{
	ft_printf("%s %d %c\n %% \tx / %X \a\n", "This is a string", 29, 'X', 124214);
	printf("%s %d %c\n %% \tx / %X \a\n", "This is a string", 29, 'X', 124214 );
	return (0);
}
