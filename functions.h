#define makeGreen       "\x1b[32m"
#define resetGreen      "\x1b[0m"
#define textColourReset "\033[0m"
#define textBlack       "\033[30m" 
#define easyBg          "\033[48;2;77;184;255m" 
#define mediumBg        "\033[48;2;255;153;51m" 
#define hardBg          "\033[48;2;255;77;106m"

#include <stdio.h>
#include <stdlib.h>

/*
    i_word = incoming word, the one to be modified
    s_word = stored word, the one to be compared to, obtained from store function
    length = length of the character string, obtained from len function
*/

void decapitalize(char guess[])
{
    int i = 0;
    while(guess[i])
    {

        if (guess[i] <= 'a' && guess[i] >= 'A')
        {

            guess[i] += 'a' - 'A';

        }
        i += 1;

    }

}
int len(char i_word[])
{
    int i = 0;
    while(i_word[i] != '\0')
    {
        i += 1;
    }
    return i;
}

void store(char i_word[], char s_word[], int length)
{
    int i = 0;
    while(i < length)
    {
        s_word[i] = i_word[i];
        i += 1;
    }
    s_word[length] = '\0';
}

void scramble(char i_word[], int length)
{
    int i = length - 1, random = 0;
    char temporary = '\0';
    while(i > 0)
    {
        random = rand() % (i + 1);
        temporary = i_word[i];
        i_word[i] = i_word[random];
        i_word[random] = temporary;
        i -= 1;
    }
}

void sortWord(char word[], int length)
{
    int i = 0, j = 0;
    char temp;
    while(i < length - 1)
    {
        j = 0;
        while(j < length - i - 1)
        {
            if(word[j] > word[j + 1])
            {
                temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
            j += 1;
        }
        i += 1;
    }
}

void hints_1_2(char s_word[], int length)
{
    printf("Hint: The first letter is '%c' and the last letter is '%c'\n", s_word[0], s_word[length - 2]);
}

void hint3(char s_word[], int length)
{
 
    char sortedCopy[20];
    store(s_word, sortedCopy, length);
    
    sortWord(sortedCopy, length);
    
    printf("Hint (Alphabetical Order): %s\n", sortedCopy);
}

void hint4(char s_word[], char guess[], int length)
{
    int i = 0;
    printf("Hint (Matched positions highlighted): ");
    
    while(i < length)
    {
        if(guess[i] != '\0' && guess[i] == s_word[i])
        {
            printf(makeGreen "%c" resetGreen, guess[i]);
        }
        else if(guess[i] != '\0')
        {
            printf("%c", guess[i]);
        }
        else
        {
            printf("_");
        }
        i += 1;
    }
    printf("\n");
}

int isCorrect(char s_word[], char guess[], int length)
{
    int i = 0;
    while(i < length)
    {
        if(s_word[i] != guess[i])
        {
            return 0; 
        }
        i += 1;
    }
    return 1; 
}
