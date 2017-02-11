#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>



string keyword_to_keynumber(string s);

string cipher(string text, string key);


int main(int argc, string argv[])
{
    //input check!
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //2nd input check!
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 'A' || argv[1][i] > 'z')
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
    }
    
    //local variables
    string p_text, c_text, k;
    
    //convert command line (string) input to int
    k = keyword_to_keynumber(argv[1]);
    
    //get text from user
    printf("plaintext: ");
    p_text = get_string();
    
    //call cipher function
    c_text = cipher(p_text, k);
    
    printf("ciphertext: %s\n", c_text);
    
    return 0;
}




string keyword_to_keynumber(string s)
{
    int a = strlen(s);
    printf("%i\n", a);
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //make case uniform
        s[i] = toupper(s[i]);
        //conversion from char to int -> ASCII value of 'A' = 65
        //cipher format -> A = 0, B = 1, etc...
        s[i] -= 'A';
        printf("%i\n", s[i]);
        printf("%i\n", n);
    }
    
    a = strlen(s);
    printf("%i\n", a);
    
    return s;
}




string cipher(string text, string key)
{
    /*
Your program must only apply Vigenère’s cipher to a character in
p if that character is a letter. All other characters (numbers, 
symbols, spaces, punctuation marks, etc.) must be outputted unchanged.
Moreover, if your code is about to apply the jth character of k to 
the ith character of p, but the latter proves to be a non-alphabetical
character, you must wait to apply that jth character of k to the next
alphabetical character in p; you must not yet advance to the next 
character in k.
*/
    
    //shift every character in string 'k' places
    for (int i = 0, j = 0, k = 0, n = strlen(text), size = strlen(key); i < n; i++)
    {
        //prevent indice for key from going out of bounds
        if (j >= size)
            j = 0;
            
        k = key[j];
        printf("%i", k);
        
        if ((text[i] >= 'A') && (text[i] <= 'Z'))
        {
            //prevent conversion from going out of bounds
            text[i] -= 26;
            //convert to ciphertext
            text[i] += key[j];
            
            //check if converted character is in correct range
            if (text[i] < 'A')
            {
                text[i] += 26;
            }
            j++;
        }
        else if ((text[i] >= 'a') && (text[i] <= 'z'))
        {
            //prevent conversion from going out of bounds
            text[i] -= 26;
            //convert to ciphertext
            text[i] += key[j];
            
            //check if converted character is the correct case
            if (text[i] < 'a')
            {
                text[i] += 26;
            }
            j++;
        }
        //else
            //do nothing
    }
    
    return text;
}