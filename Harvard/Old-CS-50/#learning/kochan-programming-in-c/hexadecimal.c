#include <stdio.h>

int main (void)
{
    int rgbColor = 0xFFEF0D;
    printf("%x\n", rgbColor);    //outputs ffef0d
    printf("%#x\n", rgbColor);    //outputs 0xffef0d
    printf("%X\n", rgbColor);    //outputs FFEF0D
    printf("%#X\n", rgbColor);    //outputs 0xFFEF0D
    return 0;
}