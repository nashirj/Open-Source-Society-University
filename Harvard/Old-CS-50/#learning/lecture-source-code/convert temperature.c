#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char scale;
    float degrees;
    do
    {
        printf("Please select Fahrenheit (F) or Celsius (C): ");
        scale = GetChar();
    }
    while (scale != 'F' && scale != 'C' && scale != 'c' && scale != 'f');
    
    printf("how many degrees %c? ", scale);
    degrees = GetFloat();
    
    if (scale == 'F' || scale == 'f')
    {
        degrees = (degrees - 32) / 1.8;
    }
    if (scale == 'c' || scale == 'C')
    {
        degrees = (degrees * 1.8) + 32;
    }
    printf("%f\n", degrees);
}