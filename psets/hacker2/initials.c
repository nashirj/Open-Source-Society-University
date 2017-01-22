#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string get_initials(string s);

int main(void)
{
    string name, initials;
    name = get_string();
    
    initials = get_initials(name);
    
    printf("%s\n", initials);
    return 0;
}



string get_initials(string s)
{
    //initialize looping variables
    int n = strlen(s);
    char temp[n];
    
    //make all the letters capital
    for (int i = 0; i < n; i++)
    {
        s[i] = toupper(s[i]);
    }
    
    //get the initials
    if (s[0] != ' ')
        temp[0] = s[0];
        
    for (int k = 0, j = 1; k < n; k++)
    {
        if (s[k] == ' ')
        {
            temp[j] = s[k+1];
            j++;
        }
    }
    
    //set s (the return value) equal to the initials
    for (int i = 0; i < n; i++)
    {
        s[i] = temp[i];
    }
    
    //return the initials
    return s;
}