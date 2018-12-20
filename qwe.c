
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = NULL;
    int fd;
    int fd1;

    fd = ft_printf("%o %o %o %o %o\n", 999988888,  1, 100, 999, 42);
    fd1 = printf("%o %o %o %o %o\n", 999988888, 1, 100, 999, 42);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
