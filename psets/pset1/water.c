/*
prompt for length of shower (in minutes)
1.5 gallons of water per minute
gallon is 128 ounces
192 ounces per minute
16 ounces per bottle
then prints the equivalent number of bottles of water (as an integer)
*/

#include <stdio.h>
#include <cs50.h>

int main (void){
    printf("minutes: ");
    int minutes = GetInt();
    int bottles = ((minutes * 192) / 16);
    printf("bottles: %i\n", bottles);
    return 0;
}