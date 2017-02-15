#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need these libraries to use the crypt function
#include <unistd.h>
#include <string.h>


int main(void)
{
    /*
    string pass1 = " ";
    printf("%c\n", pass1[0]);
    printf("%s\n", pass1);
    char temp = 'A';
    for (int i = 0; i < 26; i++)
    {
        pass1[0] = 'A';
        printf("%c\n", pass1[0]);
        printf("%s\n", pass1);
        temp++;
    }
    
    printf("\n");
    
    */
    int var1;
    char var2[10];
    
    printf("Address of var1 variable: %u\n", &var1);
    printf("Address of var2 variable: %u\n", &var2);
    
    return 0;
}