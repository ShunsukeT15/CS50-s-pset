#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int score = 0;

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%i %i", score1, score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    printf("\n");
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //小文字を大文字に
        if (islower(word[i]))
        {
            word[i] =  toupper(word[i]);
            printf("%c", word[i]);
        }
        else
        {
            printf("%c", word[i]);
        }

        int p = (int)word[i] - 65;
        score = POINTS[p];
        printf("%i\n", score);
        sum += score;
    }
    printf("%i\n", sum);

    return sum;
}