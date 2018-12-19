
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%-+10.24f\n", 21.34323);
    fd1 = printf("%-+10.24f\n", 21.34323);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
