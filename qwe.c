
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%z\n");
    fd1 = printf("%z\n");
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
