#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    
    string text = get_string();
    
    int k = 3;
    int j = 2;
    printf("%c\n", text[k]);
    printf("%c\n", text[j]);
    text[k] += 4;
    printf("%i\n", text[k]);
    
    
    //printf("%c\n", text[k] + j);
    
}