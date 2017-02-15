#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
//need this library to use the crypt function
#include <unistd.h>

string crack(string user_input);

string one_char_pass(string hash);
string two_char_pass(string hash);
string three_char_pass(string hash);
string four_char_pass(string hash);

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

string crack(string user_input)
{
    //brute force - iterate through a 4 dimensional
    //array of all possible alphabetic combinations
    //start with 1 character, move up to 2, etc...
    
    string return_val = one_char_pass(user_input);
    if (return_val != NULL)
        return return_val;
    
    return_val = two_char_pass(user_input);
    if (return_val != NULL)
        return return_val;
    
    return_val = three_char_pass(user_input);
    if (return_val != NULL)
        return return_val;
    
    return_val = four_char_pass(user_input);
    if (return_val != NULL)
        return return_val;
    
    
    return NULL;
}



string one_char_pass(string hash)
{
    //use match to compare encrypted value of possible
    //passwords to value of hash
    string match;
    
    
    //key - first number is number of letters, U for
    //upper, L for lower - i.e. 3 ULU (i.e. NiW)
    
    
    //1 LETTER PASSWORDS
    char one_char_pass[2];
    //1 U
    for (int i = 'A'; i <= 'Z'; i++)
    {
        one_char_pass[0] = i;
        //eprintf("%s\n", one_char_pass);
        match = crypt(one_char_pass, "50");
        //eprintf("%s\n", match);
        //eprintf("%s\n", hash);
        if (strcmp(hash, match) == 0)
        {
            strcpy(hash, one_char_pass);
            //why am I able to do this? isn't hash
            //defined as a constant?
            return hash;
            //wasn't able to return one_char_pass
        }
    }
    //1 L
    for (int i = 'a'; i <= 'z'; i++)
    {
        one_char_pass[0] = i;
        //eprintf("%s\n", one_char_pass);
        match = crypt(one_char_pass, "50");
        //eprintf("%s\n", match);
        //eprintf("%s\n", hash);
        if (strcmp(hash, match) == 0)
        {
            strcpy(hash, one_char_pass);
            return hash;
        }
    }
    return NULL;
}


string two_char_pass(string hash)
{
    //use match to compare encrypted value of possible
    //passwords to value of hash
    string match;
    
    
    //key - first number is number of letters, U for
    //upper, L for lower - i.e. 3 ULU (i.e. NiW)
    
    
    //2 LETTER PASSWORDS
    char two_char_pass[3];
    //2 U_
    for (int i = 'A'; i <= 'Z'; i++)
    {
        two_char_pass[0] = i;
        //eprintf("%s\n", two_char_pass);
        
        //2 UU
        for (int j = 'A'; j <= 'Z'; j++)
        {
            two_char_pass[1] = j;
            //eprintf("%s\n", two_char_pass);
            match = crypt(two_char_pass, "50");
            //eprintf("%s\n", match);
            //eprintf("%s\n", hash);
            if (strcmp(hash, match) == 0)
            {
                strcpy(hash, two_char_pass);
                return hash;
            }
        }
        //2 UL
        for (int j = 'a'; j <= 'z'; j++)
        {
            two_char_pass[1] = j;
            //eprintf("%s\n", two_char_pass);
            match = crypt(two_char_pass, "50");
            //eprintf("%s\n", match);
            //eprintf("%s\n", hash);
            if (strcmp(hash, match) == 0)
            {
                strcpy(hash, two_char_pass);
                return hash;
            }
        }
    }
    //2 L_
    for (int i = 'a'; i <= 'z'; i++)
    {
        two_char_pass[0] = i;
        //eprintf("%s\n", two_char_pass);
        //2 LU
        for (int j = 'A'; j <= 'Z'; j++)
        {
            two_char_pass[1] = j;
            //eprintf("%s\n", two_char_pass);
            match = crypt(two_char_pass, "50");
            //eprintf("%s\n", match);
            //eprintf("%s\n", hash);
            if (strcmp(hash, match) == 0)
            {
                strcpy(hash, two_char_pass);
                return hash;
            }
        }
        //2 LL
        for (int j = 'a'; j <= 'z'; j++)
        {
            two_char_pass[1] = j;
            //eprintf("%s\n", two_char_pass);
            match = crypt(two_char_pass, "50");
            //eprintf("%s\n", match);
            //eprintf("%s\n", hash);
            if (strcmp(hash, match) == 0)
            {
                strcpy(hash, two_char_pass);
                return hash;
            }
        }
    }
    return NULL;
}


string three_char_pass(string hash)
{
    //use match to compare encrypted value of possible
    //passwords to value of hash
    string match;
    
    
    //key - first number is number of letters, U for
    //upper, L for lower - i.e. 3 ULU (i.e. NiW)
    
    
    //3 LETTER PASSWORDS
    char three_char_pass[4];
    //3 U__
    for (int i = 'A'; i <= 'Z'; i++)
    {
        three_char_pass[0] = i;
        //eprintf("%s\n", three_char_pass);
        
        //3 UU_
        for (int j = 'A'; j <= 'Z'; j++)
        {
            three_char_pass[1] = j;
            //eprintf("%s\n", three_char_pass);
            
            //3 UUU
            for (int k = 'A'; k <= 'Z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
            //3 UUL
            for (int k = 'a'; k <= 'z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
        }    
        //3 UL_
        for (int j = 'a'; j <= 'z'; j++)
        {
            three_char_pass[1] = j;
            //eprintf("%s\n", three_char_pass);
            
            //3 ULU
            for (int k = 'A'; k <= 'Z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
            //3 ULL
            for (int k = 'a'; k <= 'z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
        }
    }
    //3 L__
    for (int i = 'a'; i <= 'z'; i++)
    {
        three_char_pass[0] = i;
        //eprintf("%s\n", three_char_pass);
        
        //3 LU_
        for (int j = 'A'; j <= 'Z'; j++)
        {
            three_char_pass[1] = j;
            //eprintf("%s\n", three_char_pass);
            
            //3 LUU
            for (int k = 'A'; k <= 'Z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
            //3 LUL
            for (int k = 'a'; k <= 'z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
        }    
        //3 LL_
        for (int j = 'a'; j <= 'z'; j++)
        {
            three_char_pass[1] = j;
            //eprintf("%s\n", three_char_pass);
            
            //3 LLU
            for (int k = 'A'; k <= 'Z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
            //3 LLL
            for (int k = 'a'; k <= 'z'; k++)
            {
                three_char_pass[2] = k;
                //eprintf("%s\n", three_char_pass);
                match = crypt(three_char_pass, "50");
                //eprintf("%s\n", match);
                //eprintf("%s\n", hash);
                if (strcmp(hash, match) == 0)
                {
                    strcpy(hash, three_char_pass);
                    return hash;
                }
            }
        }
    }    
    return NULL;
}



string four_char_pass(string hash)
{
    //use match to compare encrypted value of possible
    //passwords to value of hash
    string match;
    
    
    //key - first number is number of letters, U for
    //upper, L for lower - i.e. 3 ULU (i.e. NiW)
    
    
    //4 LETTER PASSWORDS
    char four_char_pass[5];
    //4 U___
    for (int i = 'A'; i <= 'Z'; i++)
    {
        four_char_pass[0] = i;
        //eprintf("%s\n", four_char_pass);
        
        //4 UU__
        for (int j = 'A'; j <= 'Z'; j++)
        {
            four_char_pass[1] = j;
            //eprintf("%s\n", four_char_pass);
            
            //4 UUU_
            for (int k = 'A'; k <= 'Z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 UUUU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 UUUL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
            //4 UUL_
            for (int k = 'a'; k <= 'z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 UULU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 UULL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
        }
        //4 UL__
        for (int j = 'a'; j <= 'z'; j++)
        {
            four_char_pass[1] = j;
            //eprintf("%s\n", four_char_pass);
            
            //4 ULU_
            for (int k = 'A'; k <= 'Z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 ULUU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 ULUL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
            //4 ULL_
            for (int k = 'a'; k <= 'z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 ULLU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 ULLL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
        }
    }
    //4 L___
    for (int i = 'a'; i <= 'z'; i++)
    {
        four_char_pass[0] = i;
        //eprintf("%s\n", four_char_pass);
        
        //4 LU__
        for (int j = 'A'; j <= 'Z'; j++)
        {
            four_char_pass[1] = j;
            //eprintf("%s\n", four_char_pass);
            
            //4 LUU_
            for (int k = 'A'; k <= 'Z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 LUUU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 LUUL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
            //4 LUL_
            for (int k = 'a'; k <= 'z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 LULU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 LULL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
        }
        //4 LL__
        for (int j = 'a'; j <= 'z'; j++)
        {
            four_char_pass[1] = j;
            //eprintf("%s\n", four_char_pass);
            
            //4 LLU_
            for (int k = 'A'; k <= 'Z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 LLUU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 LLUL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
            //4 LLL_
            for (int k = 'a'; k <= 'z'; k++)
            {
                four_char_pass[2] = k;
                //eprintf("%s\n", four_char_pass);
                
                //4 LLLU
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
                //4 LLLL
                for (int l = 'a'; l <= 'z'; l++)
                {
                    four_char_pass[3] = l;
                    //eprintf("%s\n", four_char_pass);
                    
                    match = crypt(four_char_pass, "50");
                    //eprintf("%s\n", match);
                    //eprintf("%s\n", hash);
                    if (strcmp(hash, match) == 0)
                    {
                        strcpy(hash, four_char_pass);
                        return hash;
                    }
                }
            }
        }
    }
    return NULL;
}