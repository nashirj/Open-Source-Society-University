#include <stdio.h>
#include <cs50.h>

/*

American Express numbers all start with 34 or 37
    15 digits
MasterCard numbers all start with 51, 52, 53, 54, or 55
    16 digits
Visa numbers all start with 4
    13 and 16 digits
    
   CHECKSUM ALGORITHM 
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.

2. Add the sum to the sum of the digits that weren’t multiplied by 2.

3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

*/


int main(void)
{
    printf("Number: ");
    int cardnum = GetLongLong();
    
    int card[15];
    
    for (int )
    
    switch(cardnum)
    {
        case 1:
            printf("VISA\n");
            break;
        case 2:
            printf("AMEX\n")
            break;
        case 3:
            printf("MASTERCARD\n");
            break;
        default:
            printf("INVALID\n");
            break;
    }
    
}