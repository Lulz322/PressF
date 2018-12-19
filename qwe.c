
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%24s   | %4c    |  %lf    | %+-6.10hd   |   %.12hho\n", "Dat is ME, MaRIO!", 'F', 123.456, 1337, 150);
    fd1 = printf("%24s   | %4c    |  %lf    | %+-6.10hd   |   %.12hho\n", "Dat is ME, MaRIO!", 'F', 123.456, 1337, 150);
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
