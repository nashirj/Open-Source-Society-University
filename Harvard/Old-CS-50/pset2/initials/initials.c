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
    //make all the letters capital
    int n = strlen(s);
    
    for (int i = 0; i < n; i++)
        s[i] = toupper(s[i]);
    
    //get the initials
    
    char temp[n];
    int start;
    
    //get first initial
    
    //if the first element is a char, assign it to the
    //initials array, start assigning initals at the
    //second array element
    if (s[0] != ' ')
    {
        temp[0] = s[0];
        start = 1;
    }
    //if the first element is a space, start assigning
    //initials at the first array element
    else
        start = 0;
    
    for (int k = 0, j = start; k < n; k++)
    {
        if (s[k] == ' ' && s[k+1] != ' ')
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