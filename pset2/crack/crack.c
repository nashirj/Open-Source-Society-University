#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this library to use the crypt function
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
    string input = argv[1];
    
    //crack password
    string cracked = crack(input);
    
    //print password
    printf("%s\n", cracked);
    
    return 0;
}

string crack(string hash)
{
    //brute force - iterate through a 4 dimensional
    //array of all possible alphabetic combinations
    //start with 1 character, move up to 2, etc...
    
    
    //LOWER CASE 1 LETTER PASSWORDS
    1letterpass();
    char pass1[2];
    char temp = 'A';
    char *cp = &temp;
    
    printf("%c\n", temp);
    *cp = 'G';
    printf("%c\n", temp);
    pass1[0] = *cp;
    
    printf("%c\n", pass1[0]);
    printf("%s\n", pass1);
    
    return NULL;
    
    /*
    for (int i = 0; i < 26; i++)
    {
        pass1[0] = temp;
        printf("%c\n", pass1[0]);
        printf("%s\n", pass1);
        
        match = crypt(pass1, "50");
        printf("%s\n", match);
        
        if (match == hash)
        {
            printf("match1\n");
            return pass1;
        }
        
        temp++;
    }
    //UPPER CASE 1 LETTER PASSWORDS
    temp = 'a';
    for (int j = 0; j <= 26; j++)
    {
        pass1[0] = temp;
        
        printf("%c\n", pass1[0]);
        printf("%s\n", pass1);
        
        match = crypt(pass1, "50");
        printf("%s\n", match);
        
        if (match == hash)
        {
            printf("match2\n");
            return pass1;
        }
        
        temp++;
    }
    
    */
    
    return NULL;
}