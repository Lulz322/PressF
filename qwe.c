
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd =  ft_printf("%20.15d\n", 54321);
	printf("\n");
    fd1 = printf("%20.15d\n", 54321);
	printf("\n");
    ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)\n", fd, fd1);
     //printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
