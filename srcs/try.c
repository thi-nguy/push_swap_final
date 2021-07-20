#include <stdio.h>

int main(int ac, char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        printf("argument[%d] = |%s|\n", i, av[i]);
        i++;
    }
    return (0);
}