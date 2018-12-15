
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("ast2134 2%hd,21%s\n%% %123.10, %lf5, \n)", 12322, "yyyyo\npoo", 32141.1111254);
    fd1 = printf("ast2134 2%hd,21%s\n%% %123.10, %lf5, \n)", 12322, "yyyyop\noo", 32141.1111254);
    printf("MINE : %d | YOUR  :  %d", fd1, fd);


    return (0);
}
