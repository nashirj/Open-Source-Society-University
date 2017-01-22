#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"

//MAKE FACTORIAL

int factorial(int x);

int main(void)
{
    int number = GetInt();
    int number_factorial = factorial(number);
    printf("%i", number_factorial);
}

int factorial(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    for (int i = x-1; i > 1; i--)
    {
        x *= i;
    }
    return x;
}