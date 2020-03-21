#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


string cipher(string text, string key);


int main(int argc, string argv[])
{
    //checks to ensure that only one keyword was entered
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //checks to make sure keyword is comprised solely of letters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 'A' || argv[1][i] > 'z')
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
    }
    
    //local variables
    string plain_text, cipher_text, k = argv[1];
    
    //get text from user
    printf("plaintext: ");
    plain_text = get_string();
    
    //call cipher function
    cipher_text = cipher(plain_text, k);
    
    printf("ciphertext: %s\n", cipher_text);
    
    return 0;
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
    
    //convert keyword into numeric value
    //declare array for storing converted string
    int key_length = strlen(key);
    int key_val[key_length];
    
    for (int i = 0; i < key_length; i++)
    {
        //make case uniform
        key[i] = toupper(key[i]);
        //conversion from char to int -> ASCII value of 'A' = 65
        //cipher format -> A = 0, B = 1, etc...
        key_val[i] = key[i] - 'A';
    }
    
    
    //shift every character in string 'k' places
    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        //prevent indice for key from going out of bounds
        if (j >= key_length)
            j = 0;
        
        if ((text[i] >= 'A') && (text[i] <= 'Z'))
        {
            //prevent conversion from going out of bounds
            text[i] -= 26;
            //convert to ciphertext
            text[i] += key_val[j];
            
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
            text[i] += key_val[j];
            
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