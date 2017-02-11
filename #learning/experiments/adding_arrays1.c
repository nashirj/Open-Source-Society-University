#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void){
    int size = 1000;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    for (int i = 1; i < size; i += 3)
    {
        array[i] = 1;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i]*k;
    }
    for (int i = 0; i < size; i += 23)
    {
        printf("%i\n", array[i]);
    }