#include <stdio.h>
#include <cs50.h>
#include <string.h>



int string_to_int(string s);

int power(int base, int exponent);

string cipher(string text, int key);


int main(int argc, string argv[])
{
    //input check!
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    //local variables
    string p_text, c_text;
    int k;
    
    //convert command line (string) input to int
    k = string_to_int(argv[1]);
    
    //get text from user
    printf("plaintext: ");
    p_text = get_string();
    
    //call cipher function
    c_text = cipher(p_text, k);
    
    printf("ciphertext: %s\n", c_text);
    
    return 0;
}




int string_to_int(string s)
{
    int result = 0;
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //conversion from char to int -> ASCII value of '0' = 48
        s[i] -= 48;
        //convert each number in the array to the power of ten corresponding to its decimal place
        result += s[i] * power(10, n-i-1);
    }
    
    return result;
}



int power(int base, int exponent)
{
    int result = 1;
    
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    
    return result;
}




string cipher(string text, int key)
{
   
    //convert result (k) to an integer <= 26
    key %= 26;
    
    //shift every character in string 'k' places
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'A') && (text[i] <= 'Z'))
        {
            //prevent conversion from going out of bounds
            text[i] -= 26;
            //convert to ciphertext
            text[i] += key;
            
            //check if converted character is in correct range
            if (text[i] < 'A')
            {
                text[i] += 26;
            }
        }
        else if ((text[i] >= 'a') && (text[i] <= 'z'))
        {
            //prevent conversion from going out of bounds
            text[i] -= 26;
            //convert to ciphertext
            text[i] += key;
            
            //check if converted character is the correct case
            if (text[i] < 'a')
            {
                text[i] += 26;
            }
        }
        //else
            //do nothing
    }
    
    return text;
}