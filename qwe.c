
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd = ft_printf("%lld\n", -9223372036854775808);
    fd1 = printf("%lld\n", -9223372036854775808);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
