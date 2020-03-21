/*
Implement a program that prints out a double half-pyramid of a specified height, per the below.
$ ./mario

Height: 5
   ##
  ###
 ####
#####

see: https://docs.cs50.net/2018/x/psets/1/mario/less/mario.html
*/

#include <stdio.h>
#include <cs50.h>

void make_pyramid(int height);

int main(void)
{

    int height;

    do
    {
        height = get_int("Height: ");
    }
    while ((height < 0) || (height > 23));

    make_pyramid(height);

    return 0;

}

void make_pyramid(int height){

    //outer loop makes rightmost column
    for (int i = 0; i < height; i++)
    {
        //inner loop makes rows (j = height-1 to eliminate blank at beginning of line)
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
        printf("#\n");
    }
}