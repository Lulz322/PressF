
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%lhlz");
   // fd1 = printf("%lhl");
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
