//array 1
#include <stdio.h>

int main()
{
    int a[5];
    a[0] = 1;
    a[1] = 2;
    a[2] = 5;
    a[3] = 34;
    a[4] = 1;
    for (int i=0; i<5; i++)
    {
        printf("a[%i] = %i\n", i, a[i]);
    }
}