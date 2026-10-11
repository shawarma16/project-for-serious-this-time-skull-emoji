#define makeGreen   "\x1b[32m"
#define resetGreen   "\x1b[0m"
#include <stdio.h>
#include <stdlib.h>

/*

    i_word = incoming word, the one to be modified
    s_word = stored word, the one to be compared to, obtained from store function
    length = length of the character string, obtained from len function


*/

int len(char i_word[])
{
    int i = 0;
    while(i_word[i])
    {

        i += 1;

    }
    return i;

}


void store(char i_word[], char s_word[], int length)
{
    int i = 0;
    while(i < length - 1)
    {

        s_word[i] = i_word[i];
        i += 1;

    }
    s_word[length - 1] = '\0';

}

void scramble(char i_word[], int length)
{

    int i = length - 1, random = 0;
    char temporary = '\0';
    while(i)
    {

        random = rand() % (i + 1);
        temporary = i_word[i];
        i_word[i] = i_word[random];
        i_word[random] = temporary;
        i -= 1;

    }

}

char hints_1_2(char s_word[],int hint,int length)
{

    char h1 = s_word[0];
    char h2 = s_word[length - 2];

}

void hint3(char i_word[])
{

    if (hint == 3)
    {
        int i = 0;
        char min = i_word[0];
          while(i < length -1)
          {

                while()

          } 

    }

}

char hint4(char s_word[], char guess[], int hint, int length)
{
    int i = 0;
    if (hint == 4)
    {

        while(i < length)
        {

            if(guess[i] == s_word[i])
            {

                printf(makeGreen"%c"resetGreen,guess[i]);

            }
            else
            {
                printf("%c",guess[i]);
            }
            i += 1;
        }
        printf("\n");

    }
    /*
    
    HINT 3
        accessible completely on easy and medium difficulty
        only 25%~30% of the word will be hinted, mostly spaced out, and not in not in conglomerates
    */

}
/*
Functions will most likely include


The one that makes the letters green DONE
The one that scrambles DONE
The one that sortst
The one that gives hints one and two DONE
The one that makes it feel like a game i swear bro


*/