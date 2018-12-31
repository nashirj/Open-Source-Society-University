//Implement a program that prints out a double half-pyramid of a specified height, per the below.
/*
   #  #
  ##  ##
 ###  ###
####  ####

see: https://docs.cs50.net/2018/x/psets/1/mario/more/mario.html
*/

#include <stdio.h>
#include <cs50.h>

void make_pyramid(int height);

int main(void)
{
    int user_input;

    do
    {
        printf("height: ");
        user_input = get_int();
    }
    while ((user_input < 0) || (user_input > 23));

    make_pyramid(user_input);

    return 0;
}


void make_pyramid(height)
{
    //outer loop makes rightmost column
    for (int i = 0; i < height; i++)
    {
        //first loop makes left hand side of rows
        for (int j = height - 1; j >= 0; j--)
        {
            if (j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("  ");

        //second loop makes right hand side of rows
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