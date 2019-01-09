
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



	fd = ft_printf("%C\n", 15000);
	ft_printf("\n");
	fd1 = printf("%C\n", 15000);
	printf("\n");


//
	ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
    return (0);
}
