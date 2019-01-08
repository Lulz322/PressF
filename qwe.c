
#include "includes/ft_printf.h"
#include <signal.h>

int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

	fd = ft_printf("%c", 0);
	printf("\n");
	fd1 = printf("%c", 0);
	printf("\n");
	ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
	printf("\n");
	fd = ft_printf("%s%p%d%d%p%s%p%p%s",
	          "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c")  ;
	printf("\n");
	fd1 = printf("%s%p%d%d%p%s%p%p%s",
	             "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c")  ;
	printf("\n");
    ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);

    return (0);
}
