#include <stdio.h>
#include <cs50.h>
#include <string.h>



long power(int base, int exponent);

int main(void)
{
    printf("input base: ");
    int i = get_int();
    printf("input power: ");
    int j = get_int();
    
    printf("the result is %li\n", power(i, j));
    return 0;
}

long power(int base, int exponent)
{
    long result = 1;
    
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    
    return result;
    
}