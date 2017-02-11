#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need these libraries to use the crypt function
#include <unistd.h>


string crack(string hash);

int main(int argc, string argv[])
{
    //input check!
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    //get hashed password
    string hash = argv[1];
    
    //encode password
    hash = crypt(argv[1], "50");
    
    //crack password
    string cracked = crack(hash);
    
    //print password
    printf("%s\n", cracked);
    
    return 0;
}

string crack(string hash)
{
    //string password;
    
    //brute force - iterate through a 4 dimensional array of all possible alphabetic combinations
    //start with 1 character, move up to 2, etc...
    
    for (int i = 'A'; i <= 'Z'; i++)
    {
        printf("%c", i);
    }
    for (int j = 'a'; j <= 'z'; j++)
    {
        printf("%c", j);
    }
    
    return hash;
}