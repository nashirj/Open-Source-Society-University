//array
#include <stdio.h>

int main()
{
    int a[5];
    int i;

    for (i=0; i<5; i++)
    {
        a[i] = i*i;
    }
        
    for (i=0; i<5; i++)
    {
        printf("a[%i] = %i\n", i, a[i]);
    }
}