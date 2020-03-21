#include <stdio.h>
#include <cs50.h>
#include <math.h>

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


/*
You can use arithmetic to loop through the numbers and sum them at the same time.
Recall that 123456%10 = 6 which leads on to (123456/10) %10 = 5 and 123456/100 = 1234
Maybe that will give you a hint.
*/

int main(void)
{
    
    long long cardNum;
    
    printf("Number: ");
    cardNum = GetLongLong();
    
    int cardLength;
    int cardVal; //0 = visa, 1 = amex, 2 = mastercard;
    
    if (cardNum >= 4000000000000 && cardNum < 5000000000000)
    {
        cardLength = 13;
        //VISA
        cardVal = 0;
    }
    else if (cardNum >= 4000000000000000 && cardNum < 5000000000000000)
    {
        cardLength = 16;
        //VISA
        cardVal = 0;
    }
    else if ((cardNum >= 340000000000000 && cardNum < 350000000000000) || (cardNum >= 370000000000000 && cardNum < 380000000000000))
    {
        cardLength = 15;
        //AMEX
        cardVal = 1;
    }
    else if (cardNum >= 5100000000000000 && cardNum < 5600000000000000)
    {
        cardLength = 16;
        //MASTERCARD
        cardVal = 2;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    int doubled_sum = 0, unaltered_sum = 0;
    
    //get sum of every other digit starting with 2nd to last
    for (int counter = 1; counter < cardLength; counter += 2)
    {
        //set place value for modulo
        long divisor = pow(10, counter);
        if (((cardNum/divisor)%10) < 5)
        {
            doubled_sum += ((cardNum/divisor)%10) * 2;
        }
        else if (((cardNum/divisor)%10) > 4)
        {
            int temp, ones, tens;
            temp = ((cardNum/divisor)%10);
            temp *= 2;
            ones = temp%10;
            tens = temp/10;
            doubled_sum += tens + ones;
        }
    }
    
    //get sum of every other digit starting with last
    for (int counter = 0; counter < cardLength; counter += 2)
    {
        long divisor = pow(10, counter);
        unaltered_sum += ((cardNum/divisor)%10);
    }
    
    int total = unaltered_sum + doubled_sum;
    
    if (total%10 == 0)
    {
        switch(cardVal)
        {
            case 0:
            {
                printf("VISA\n");
                break;
            }
            case 1:
            {
                printf("AMEX\n");
                break;
            }
            case 2:
            {
                printf("MASTERCARD\n");
                break;
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}