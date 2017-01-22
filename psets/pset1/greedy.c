#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    float change;
    int quarter = 25, dime = 10, nickel = 5, penny = 1;
    int coins = 0;
    
    printf("O hai! ");
    
    do
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    }while(change < 0);
    
    //TYPECAST
    int rounded_change = round(change * 100);
    
    if (rounded_change == 0)
    {
        printf("%i\n", coins);
    }
    else
    {
        do
        {
            if (rounded_change >= quarter)
            {
                rounded_change -= quarter;
                coins++;
            }
            else if (rounded_change >= dime)
            {
                rounded_change -= dime;
                coins++;
            }
            else if (rounded_change >= nickel)
            {
                rounded_change -= nickel;
                coins++;
            }
            else if (rounded_change >= penny)
            {
                rounded_change -= penny;
                coins++;
            }
        }while (rounded_change > 0);
        
        printf("%i\n", coins);
        
    }
    
    return 0;
    
}