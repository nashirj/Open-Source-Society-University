#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdbool.h>

#define SALT "50"

int main(int argc, char **argv ){
    //validate number of command line args
    if (argc != 2){
        printf("Usage: ./crack hash\n");
        return 1;
    }

    //encrypt password
    printf("%s\n", crypt(argv[1], SALT));

}