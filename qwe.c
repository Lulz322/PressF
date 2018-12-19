
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";
    int fd;
    int fd1;

    fd = ft_printf("%24s   | %22c\n", "Dat is ME, MaRIO!", 'F');
    fd1 = printf("%24s   | %22c\n", "Dat is ME, MaRIO!", 'F');
    printf("MINE : %d | YOUR  :  %d", fd, fd1);


    return (0);
}
