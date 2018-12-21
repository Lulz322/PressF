
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "qeqwe";
    int fd;
    int fd1;
    unsigned long l;

    fd = ft_printf("%s\n", "this is a string");
    fd1 = printf("%s\n", "this is a string");
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
