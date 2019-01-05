
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd =  ft_printf("%5+d", 42);
	printf("\n");
    fd1 = printf("%5+d", 42);
	printf("\n");
    ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
     //printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
