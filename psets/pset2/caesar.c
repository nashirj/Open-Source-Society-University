#include <stdio.h>
#include <cs50.h>
#include <string.h>



int string_to_int(string s);

int power(int base, int exponent);

string cipher(string p_text, int key);


int main(int argc, string argv[])
{
    //input check!
    if (argc != 2)
    {
        printf("please specify 1 command line argument!\n");
        return 1;
    }
    
    //local variables
    string text;
    int k;
    
    //convert command line (string) input to int
    k = string_to_int(argv[1]);
    
    //get text from user
    printf("plaintext: ");
    text = get_string();
    
    //call cipher function
    text = cipher(text, k);
    
    printf("ciphertext: %s\n", text);
    
    return 0;
}




int string_to_int(string s)
{
    //use technique from credit card number function to convert to an int
    
    int n = strlen(s);
    int converted_string[n];
    
    for (int i = 0, exp; i < n; i++)
    {
        exp = (power(10, n-i-1));
        converted_string = s[i] * exp;
        
        /*
        int i = (int)temp[i];
        i -= 48;
        
        //ASCII conversion -> '0' = 48
        
        //convert k to an integer <= 26
        k %= 26;
        printf("%i\n", i);
        */
    }
    
    return converted_string;
}



int power(int base, int exponent)
{
    
}



string cipher(string p_text, int key)
{
    //shift every character in string 'k' places
    
    string c_text;
    
    for (int i = 0, n = strlen(p_text); i < n; i++)
    {
        s[i] = s[i+k];
    }
    
    return c_text;
}