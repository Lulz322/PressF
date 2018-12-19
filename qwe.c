
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%s\n", "213sadr21\n");
    fd1 = printf("%s\n", "213sadr21\n");
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
