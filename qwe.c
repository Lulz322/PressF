
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%x\n", 2132142);
    fd1 = printf("%x\n", 2132142);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
