/*
Implement a program that calculates the minimum number of coins required to give a user change.

$ ./cash
Change owed: 0.41
4

see: https://docs.cs50.net/2018/x/psets/1/cash/cash.html
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int greedy(int value);

int main(void)
{
    float user_input;

    do
    {
        printf("Change owed: ");
        //get_float() validates input, loops until nonnegative number entered
        user_input = get_float();
    }
    while (user_input < 0);

    //TYPECAST to cents - ensures no rounding errors
    int change = round(user_input * 100);

    int ans = greedy(change);

    printf("%i\n", ans);

    return 0;
}

int greedy(int value)
{
    int numCoins = 0;

    //take largest chunk out of program possible during each iteration "greedy algorithm"
    while(value > 0){
        if (value >= QUARTER)
        {
            value -= QUARTER;
            numCoins++;
        }
        else if (value >= DIME)
        {
            value -= DIME;
            numCoins++;
        }
        else if (value >= NICKEL)
        {
            value -= NICKEL;
            numCoins++;
        }
        else //if (value >= PENNY)
        {
            value -= PENNY;
            numCoins++;
        }
    }

    return numCoins;

}