//need to define in order to use crypt function
#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this libraries to use the crypt function
#include <unistd.h>


string crack(const char* hash);

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
    printf("%s\n", password);
    eprintf("1main\n\n");
    
    
    
    //encode password
    const char* hash = crypt(password, "50");
    printf("%s\n", hash);
    eprintf("2main\n\n");
    
    
    
    //check password against encoded strings password
    string cracked = crack(hash);
    
    
    printf("%s\n", hash);
    eprintf("swagmain\n\n");
    printf("%s\n", password);
    eprintf("swag\n\n");
    
    
    
    
    //check value of hash
    printf("%s\n", hash);
    eprintf("3main\n\n");
    
    
    
    //print password
    printf("%s\n", cracked);
    eprintf("4main\n\n");
    
    
    
    return 0;
}

string crack(const char* hash)
{
    string match;
    string pass;
    
    printf("%s\n", hash);
    eprintf("1crack\n\n");
    
    //brute force - iterate through a 4 dimensional array of all possible alphabetic combinations
    //start with 1 character, move up to 2, etc...
    
    //UPPER CASE 1 LETTER PASSWORDS
    for (char i = 'A'; i <= 'Z'; i++)
    {
        pass = &i;
        
        printf("%s\n", hash);
        printf("%s\n", pass);
        
        match = crypt(&i, "50");
        
        printf("%s\n", match);
        eprintf("2crack\n\n");
        
        printf("%s\n", hash);
        eprintf("3crack\n\n");
        
        if (match == hash)
        {
            printf("match1\n");
            eprintf("4crack\n\n");
            return pass;
        }
    }
    //LOWER CASE 1 LETTER PASSWORDS
    for (char i = 'a'; i <= 'z'; i++)
    {
        pass = &i;
        
        eprintf("%s\n", pass);
        
        match = crypt(&i, "50");
        if (match == hash)
        {
            printf("match2\n");
            eprintf("5crack\n\n");
            return pass;
        }
    }
    
    //2 letter password
    
    
    return NULL;
}