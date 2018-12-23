
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd = ft_printf("MGRN(%.10d)\n", 124214);
    fd1 = ft_printf("MRED(%.10d)\n", 124214);
    ft_printf("MYLW(MINE) : MCYN(%d) | MRED(YOUR)  :  MBLU(%d)", fd, fd1);
  //  printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
