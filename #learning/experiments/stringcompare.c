#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this library to use the crypt function
#include <unistd.h>

int main(void)
{
    string hash = get_string();
string swag = get_string();

int n1 = strlen(hash), n2 = strlen(swag), count = 0;
    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
            if (swag[i] == hash[i])
                count++;
        if (count == n1)
        {
            printf("identical strings!\n");
            return 0;
        }
        else
        {
            printf("strings are not identical\n");
            return 1;
        }
    }
    else
    {
        printf("strings are not same length\n");
        return 1;
    }
}
