#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compute_k(const char *str);
int k;

int main(int argc,char *argv[])
{
    //入力が正しいか　（引数の数）
    if(argc != 2)
    {
        printf("Usage: ./caesar key1\n");
        return 1;
    }

    //入力が正しいか　（keyが数値かの判別）
    int key,kc;

    kc = compute_k(argv[1]);

    if(kc == 1)
    {
        printf("Usage: ./caesar key\n");
    }
    else if(kc == 0)
    {
        key = k;
        string text = get_string("painttext: ");
        printf("ciphertext:");

        //暗号変換
        for(int j = 0, m = strlen(text); j < m; j++)
        {
            if('A' <= text[j] && text[j] <= 'Z')
            {
                text[j] ='A' + ((text[j] - 'A' + key) % 26);
                printf("%c",text[j]);
            }
            else if('a' <= text[j] && text[j] <= 'z')
            {
                text[j] ='a' + ((text[j] - 'a' + key) % 26);
                printf("%c",text[j]);
            }
            else
            {
                printf("%c",text[j]);
            }
        }

        printf("\n");

    }

    return 0;
}

int compute_k(const char *str)
{
    for(int i = 0, n = strlen(str); i < n; i++)
    {
        if(str[i] < '0' || '9' < str[i])
        {
            printf("str %s\n",str);
            return 1;
        }

        k = atoi(str);
    }

    return 0;
}