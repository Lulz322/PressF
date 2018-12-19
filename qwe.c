
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%#+s   %d\n", "2131", 214124);
    fd1 = printf("%#+s   %d\n", "2131", 214124);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
