#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2){
        printf("error, invalid number of command line args\n");
        return 1;
    }

    int k = atoi(argv[1]) % 26;
    printf("%d\n", k);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    int sLen = strlen(plaintext);
    char cipher[sLen];

    for (int i = 0; i < sLen; i++){
        char curr = plaintext[i];
        if (islower(curr)){
            if (curr + k <= 'z')
                cipher[i] = curr + k;
            else
                cipher[i] = curr + k - 26;
        }
        else if (isupper(curr)){
            if (curr + k <= 'Z')
                cipher[i] = curr + k;
            else
                cipher[i] = curr + k - 26;
        }
        else
            cipher[i] = curr;
        printf("%c", cipher[i]);
    }
    printf("\n");

    return 0;
}