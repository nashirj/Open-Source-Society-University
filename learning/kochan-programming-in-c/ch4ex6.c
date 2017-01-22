#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int x = GetInt();
    x = 3*(x*x*x) - 5*(x*x) + 6;
    printf("%i", x);
    return 0;
}

//3x3 - 5x2 + 6