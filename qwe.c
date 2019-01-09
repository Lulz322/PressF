
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



	fd = ft_printf("%.p, %.0p", 0, 0);
	ft_printf("\n");
	fd1 = printf("%.p, %.0p", 0, 0);
	printf("\n");


//
	ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
    return (0);
}
