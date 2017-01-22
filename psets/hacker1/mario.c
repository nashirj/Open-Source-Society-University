#include <stdio.h>
#include <cs50.h>

void make_pyramid(int height);

int main(void)
{
    
    int input;
    
    do
    {
        printf("Enter a non-negative integer < 24: ");
        input = GetInt();
    } while ((input < 0 )||(input >23));
    
    make_pyramid(input);
    
    return 0;
}



void make_pyramid(int height)
{
    //the outermost loop makes the middle 2 columns
    for (int i = 0; i < height; i++)
    {
        //this loop makes the first part of the row
        for (int j = 1; j <= height; j++)
        {
            if (j >= (height - i))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        
        for (int k = 0; k < height; k++)
        {
            if (k <= i)
            {
                printf("#");
            }
        }
        
        printf("\n");

    }
}