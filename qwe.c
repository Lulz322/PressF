
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd = ft_printf("%zs\n", "123");
    fd1 = printf("%zs\n", "123");
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
