
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd =  ft_printf("%llu\n", -123456);
    printf("\n");
    fd1 = printf("%llu\n", -123456);
    printf("\n");
    ft_printf("MYLW(MINE) :MXUI( MCYN(%d) | MRED(YOUR)  :  MBLU(%d)", fd, fd1);
     //printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
