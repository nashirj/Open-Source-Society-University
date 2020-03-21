#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int height;
    
    do
    {
        printf("height: ");
        height = GetInt();
    } while ((height < 0 )||(height >23));
    
    //the outermost loop makes the rightmost column
    for (int i = 0; i < height; i++)
    {
        //this loop makes the rows
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
        printf("#\n");
    }
    
}