
#include "includes/ft_printf.h"


int main(void)
{
    char *qwe = "ewoihewro";

    ft_printf("%0101lf\n", 5124.3);
    printf("%s\n%0101lf", "Test", 5124.3);

    return (0);
}
