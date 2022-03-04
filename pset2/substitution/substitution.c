#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./subsutitution key\n");
        return 1;
    }

    char *key_set = argv[1];
    int key_number[27];
    key_number[26] = 0;

    if (strlen(key_set) != 26)
    {
        printf("Key must contein 26 characters.\n");
        return 1;
    }


    for (int i = 0; i < 26; i++)
    {
        char key = tolower(key_set[i]);
        if (key < 'a' || 'z' < key)
        {
            printf("%c is not alphabet.\n", key);
            return 1;
        }
        for (int j = 0; j < 26; j++)
        {
            char key2 = tolower(key_set[j]);
            if (key2 == key && i != j)
            {
                printf("Overlapping characters in key_set.\n");
                return 1;
            }
        }

        if ('a' <= key && key <= 'z')
        {
            key_number[i] = key - ('a' + i);
        }
    }

    string text = get_string("plaintext:");
    printf("ciphertext:");
    for (int i = 0; i < strlen(text); i++)
    {
        int index = 26;
        if ('A' <= text[i] && text[i] <= 'Z')
        {
            index = text[i] - 'A';
        }
        else if ('a' <= text[i] && text[i] <= 'z')
        {
            index = text[i] - 'a';
        }
        printf("%c", text[i] + key_number[index]);
    }
    printf("\n");
    return 0;
}
