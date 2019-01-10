
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
	    fd = ft_printf("%ju", 4294967296);
	    ft_printf("\n");
	    fd1 = printf("%ju", 4294967296);
	    printf("\n");


//
	ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
    }
    return (0);
}
