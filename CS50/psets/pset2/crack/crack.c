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
string five_char_pass(string hash);

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
    if (cracked != NULL)
        printf("%s\n", cracked);
    else
        printf("password not cracked...\n");

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

    return_val = five_char_pass(user_input);
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


string five_char_pass(string hash){
    //use match to compare encrypted value of possible
    //passwords to value of hash
    string match;

    printf("starting five pass\n");

    //key - first number is number of letters, U for
    //upper, L for lower - i.e. 3 ULU (e.g. NiW)

    //5 LETTER PASSWORDS
    char five_char_pass[6];
    //5 U____
    for (int i = 'A'; i <= 'Z'; i++)
    {
        eprintf("U____\n");
        five_char_pass[0] = i;
        //eprintf("%s\n", five_char_pass);

        //5 UU___
        for (int j = 'A'; j <= 'Z'; j++)
        {
            eprintf("UU___\n");
            five_char_pass[1] = j;
            //eprintf("%s\n", five_char_pass);

            //5 UUU__
            for (int k = 'A'; k <= 'Z'; k++)
            {
                eprintf("UUU__\n");
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 UUUU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    eprintf("UUUU_\n");
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 UUUUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        eprintf("UUUUU\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 UUUUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        eprintf("UUUUL\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //5 UUUL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    eprintf("UUUL_\n");
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 UUULU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        eprintf("UUULU\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 UUULL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        eprintf("UUULL\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
            //5 UUL__
            for (int k = 'a'; k <= 'z'; k++)
            {
                eprintf("UUL__\n");
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 UULU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    eprintf("UULU_\n");
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 UULUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        eprintf("UULUU\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 UULUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        eprintf("UULUL\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //5 UULL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    eprintf("UULL_\n");
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 UULLU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        eprintf("UULLU\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 UULLL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        eprintf("UULLL\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
        }
        //5 UL___
        for (int j = 'a'; j <= 'z'; j++)
        {
            eprintf("UL___\n");
            five_char_pass[1] = j;
            //eprintf("%s\n", five_char_pass);

            //5 ULU__
            for (int k = 'A'; k <= 'Z'; k++)
            {
                eprintf("ULU__\n");
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 ULUU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    eprintf("ULUU_\n");
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 ULUUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        eprintf("ULUUU\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 ULUUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        eprintf("ULUUL\n");
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //5 ULUL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    eprintf("ULUL_\n");
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 ULULU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 ULULL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
            //5 ULL__
            for (int k = 'a'; k <= 'z'; k++)
            {
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 ULLU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 ULLUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 ULLUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //5 ULLL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 ULLLU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 ULLLL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
        }
    }
    //5 L____
    for (int i = 'a'; i <= 'z'; i++)
    {
        eprintf("L____\n");
        five_char_pass[0] = i;
        //eprintf("%s\n", five_char_pass);

        //5 LU___
        for (int j = 'A'; j <= 'Z'; j++)
        {
            five_char_pass[1] = j;
            //eprintf("%s\n", five_char_pass);

            //5 LUU__
            for (int k = 'A'; k <= 'Z'; k++)
            {
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 LUUU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LUUUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LUUUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }

                //5 LUUL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LUULU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LUULL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
            //5 LUL__
            for (int k = 'a'; k <= 'z'; k++)
            {
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 LULU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LULUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LULUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //5 LULL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LULLU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LULLL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
        }
        //5 LL___
        for (int j = 'a'; j <= 'z'; j++)
        {
            five_char_pass[1] = j;
            //eprintf("%s\n", five_char_pass);

            //5 LLU__
            for (int k = 'A'; k <= 'Z'; k++)
            {
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 LLUU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LLUUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LLUUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //5 LLUL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LLULU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LLULL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
            //5 LLL__
            for (int k = 'a'; k <= 'z'; k++)
            {
                five_char_pass[2] = k;
                //eprintf("%s\n", five_char_pass);

                //5 LLLU_
                for (int l = 'A'; l <= 'Z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LLLUU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LLLUL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
                //4 LLLL_
                for (int l = 'a'; l <= 'z'; l++)
                {
                    five_char_pass[3] = l;
                    //eprintf("%s\n", five_char_pass);

                    //5 LLLLU
                    for (int m = 'A'; m <= 'Z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                    //5 LLLLL
                    for (int m = 'a'; m <= 'z'; m++)
                    {
                        five_char_pass[4] = m;
                        //eprintf("%s\n", five_char_pass);

                        match = crypt(five_char_pass, "50");
                        //eprintf("%s\n", match);
                        //eprintf("%s\n", hash);
                        if (strcmp(hash, match) == 0)
                        {
                            strcpy(hash, five_char_pass);
                            return hash;
                        }
                    }
                }
            }
        }
    }
    return NULL;
}