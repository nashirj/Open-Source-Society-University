//need to define in order to use crypt function
#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this libraries to use the crypt function
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
    
    //get password
    string password = argv[1];
    
    //encode password
    string hash = crypt(password, "50");
    printf("%s\n", hash);
    
    //check password against encoded strings password
    char cracked = crack(hash);
    
    //check value of hash
    printf("%s\n", hash);
    
    //print password
    printf("%c\n", cracked);
    
    return 0;
}

char crack(string hash)
{
    string temp;
    
    //brute force - iterate through a 4 dimensional array of all possible alphabetic combinations
    //start with 1 character, move up to 2, etc...
    
    //UPPER CASE 1 LETTER PASSWORDS
    for (char s = 'A'; s <= 'Z'; s++)
    {
        temp[0] = s;
        //problem starts here
        if (hash == (crypt(temp, "50")))
        {
            printf("%s\n\n", hash);
            printf("match1\n");
            return s;
        }
    }
    //LOWER CASE 1 LETTER PASSWORDS
    for (char s = 'a'; s <= 'z'; s++)
    {
        temp[0] = s;
        //problem starts here
        if (hash == (crypt(s, "50")))
        {
            printf("%s\n\n", hash);
            printf("match1\n");
            return s;
        }
    }
    
    //2 letter password
    
    
    return '1';
}