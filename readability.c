//submitted by Michael Plescia

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int letter;
int word;
int sentence;

int main(void)

{
    string article = get_string("Text: ");

    int n = strlen(article);

    if (isalnum(article[0]))
    {
        word = 1;
    }
    for (int i = 0; i < n;  i++)
    {
        if (isalnum(article[i]))
        {
            letter++;
        }
        if (i < n - 1 && isspace(article[i]) && isalnum(article[i + 1]))
        {
            word++;
        }
        if (i > 0 && (article[i] == '!' || article[i] == '?' || article[i] == '.') && isalnum(article[i - 1]))
        {
            sentence++;
        }

    }
    int grade = 0.0466 * (100 * letter / word) - 0.390 * (100 * sentence / word) - 16.7;
    
    printf("Letter: %i\n Word: %i\n Sentence: %i\n", letter, word, sentence);

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}