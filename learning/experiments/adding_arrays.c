#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    
    string text = "hi there";
    
    int k = 3;
    int j = 2;
    printf("%c\n", text[k]);
    printf("%c\n", text[j]);
    printf("%c\n", text[k] + j);
    text[k] += 48;
    printf("%c\n", text[k]);
    
}
