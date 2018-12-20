
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = NULL;
    int fd;
    int fd1;

    fd = ft_printf("%c\n", 0);
    fd1 = printf("%c\n", 0);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
