#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need these libraries to use the crypt function
#include <unistd.h>


char crack(string hash);

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
    printf("%s\n", hash);
    
    //encode password
    hash = crypt(argv[1], "50");
    printf("%s\n", hash);
    
    //crack password
    char cracked = crack(hash);
    
    //print password
    printf("%c\n", cracked);
    
    return 0;
}

char crack(string hash)
{
    char password[1];
    string match;
    
    //brute force - iterate through a 4 dimensional array of all possible alphabetic combinations
    //start with 1 character, move up to 2, etc...
    
    //1 letter password
    for (char i = 'A'; i <= 'Z'; i++)
    {
        password[0] = i;
        match = crypt(&i, "50");
        printf("%s\n", match);
        printf("%s\n", hash);
        if (match == hash)
        {
            printf("match1\n");
            return i;
        }
            
    }
    for (char j = 'a'; j <= 'z'; j++)
    {
        password[0] = j;
        match = crypt(&j, "50");
        if (match == hash)
        {
            printf("match2\n");
            return j;
        }
    }
    
    //2 letter password
    
    
    return password[0];
}