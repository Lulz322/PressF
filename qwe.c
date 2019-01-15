
#include "includes/ft_printf.h"
//#include "include/ft_printf.h"
#include <signal.h>
#include <limits.h>
#include <signal.h>

int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long i;


	i = 0;
    while (i++ < 5) {
	    fd = ft_printf("%lX, %lX", 0, ULONG_MAX);
	    ft_printf("\n");
	    fd1 = printf("%lX, %lX", 0, ULONG_MAX);
	    printf("\n");


//
	ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
    }
    system("leaks a.out");
    return (0);
}
