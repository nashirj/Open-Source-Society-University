#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void cipher(string plaintext, string k);

int main(int argc, string argv[])
{
    //validate number of command line args
    if (argc != 2){
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string k = argv[1];
    int kLen = strlen(k);

    //validate value of keyword
    for (int i = 0; i < kLen; i++){
        if (!isalpha(k[i])){
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    cipher(plaintext, k);

    return 0;
}

void cipher(string plaintext, string k){
    //kPos iterates over characters of keyword
    int kPos = 0;
    int kLen = strlen(k), pLen = strlen(plaintext);

    for (int i = 0; i < pLen; i++){
        //if all chars of keyword used, start again at beginning
        if(kPos == kLen)
            kPos = 0;

        char curr = plaintext[i];

        if (!isalpha(curr)){
            printf("%c", curr);
            continue;
        }

        int key = k[kPos];
        if (isupper(key))
            key -= 'A';
        else
            key -= 'a';

        if (isupper(curr)){
            if (curr + key <= 'Z')
                printf("%c", curr + key);
            else
                printf("%c", curr + key - 26);
        }
        else if (islower(curr)){
            if (curr + key <= 'z')
                printf("%c", curr + key);
            else
                printf("%c", curr + key - 26);
        }
        //else
            //do nothing, not possible to get here?
        kPos++;
    }
    printf("\n");

}