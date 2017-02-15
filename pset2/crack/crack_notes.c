#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this library to use the crypt function
#include <unistd.h>

int main(void)
{
    string pass = "A";
    printf("%s\n", pass);
    
    string swag = crypt(pass, "50");
    printf("%s\n", swag);
    printf("%s\n", hash);
    
    int n1 = strlen(hash), n2 = strlen(swag), count = 0;
    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
            if (swag[i] == hash[i])
                count++;
        if (count == n1)
            return "identical strings!";
        else
            return "strings are not identical";
    }
    else
        return "strings are not same length";
}
        /*
        When passing variables into functions, you have to use pointers or references
If you want to modify the variable, Just keep that in mind 
Because you need the address of the variable so that you can modify it
Memory address*
*/