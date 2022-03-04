#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float count_letter(string text);

int count_letters = 0;
int count_words = 1;
int count_sentences = 0;


int main(int argc, string argv[])
{
    //文字の入力
    string text1 = get_string("Text: ");

    float score1 = count_letter(text1);
    int index = round(score1);

    printf("score1 = %f\n",score1);
    printf("index = %d\n",index);

    if(index < 1)
    {
        printf("Before Grade 1");
    }
    else if(1 <= index && index <= 16)
    {
        printf("Grade %i\n",index);
    }
    else
    {
        printf("Grade 16+");
    }
}

float count_letter(string text)
{
    //文字,単語,文章数カウント
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(('0' <= text[i] && text[i] <= '9') || ('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z'))
        {
            count_letters ++;
        }
        if(1 <= i && text[i-1] != ' ' && text[i] ==' ')
        {
            count_words ++;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences ++;
        }
    }

    printf("letters = %i\n",count_letters);
    printf("words = %i\n",count_words);
    printf("sentences = %i\n",count_sentences);

    float L = 100 * (float)count_letters / (float)count_words;
    float S = 100 * (float)count_sentences / (float)count_words;
    printf("L = %f\n",L);
    printf("S = %f\n",S);

    //Coleman-Liau指数の計算
    float score = 0.0588 * L - 0.296 * S - 15.8;

    return score;
}