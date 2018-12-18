
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%Lf\n", 32211.12341);
    fd1 = printf("%Lf\n", 32211.12341);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
