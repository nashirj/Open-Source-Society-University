#include <stdio.h>
#include <cs50.h>

// function prototype
int cube(int a);

int main(void)
{
    printf("please give me an int: ");
    int x = GetInt();
    printf("x is now %i\n", x);
    printf("Cubing...\n");
    x = cube(x);
    printf("Cubed!\n");
    printf("x is now %i\n", x);
}

/**
 * Cubes argument.
 */
int cube(int n)
{
    return n * n * n;
}