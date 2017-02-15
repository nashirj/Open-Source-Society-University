#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this library to use crypt();
#include <unistd.h>

int main(void)
{
    string crack = "a";
    printf("%s\n", crypt(crack, "50"));
}