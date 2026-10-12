#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

#define makeGreen "\x1b[32m"
#define resetGreen "\x1b[0m"

int main()
{
    srand(time(NULL));

    char mammals[4][20] = {"dolphin", "kangaroo", "cheetah", "gorilla"};
    char birds[4][20] = {"flamingo", "ostrich", "peacock", "penguin"};
    char fishes[4][20] = {"salmon", "catfish", "sardine", "goldfish"};
    char insects[4][20] = {"beetle", "spider", "cicada", "cricket"};
    char sports[4][20] = {"football", "tennis", "hockey", "curling"};
    char weather[4][20] = {"breeze", "thunder", "blizzard", "tornado"};
    char kitchen[4][20] = {"blender", "toaster", "spatula", "grater"};
    char fruits[4][20] = {"banana", "cherry", "orange", "avocado"};

    char words[4][20];
    char answers[4][20];
    char guess[20];

    char (*selected)[20];

    int level = 0;
    int i = 0;
    int j = 0;
    int attempts = 0;
    int correct = 0;
    int length = 0;
    int score = 0;

    printf("========================================\n");
    printf("           OMM SRI SAI RAM\n");
    printf("========================================\n");
    printf("       WELCOME TO WORD PUZZLE!\n");
    printf("========================================\n\n");

    printf("SELECT YOUR LEVEL:\n\n");

    printf("1. Mammals\n");
    printf("2. Birds\n");
    printf("3. Fishes\n");
    printf("4. Insects\n");
    printf("5. Sports\n");
    printf("6. Weather\n");
    printf("7. Kitchen\n");
    printf("8. Fruits\n\n");

    printf("Enter level (1-8): ");
    scanf("%d", &level);

    switch(level)
    {
        case 1:
            selected = mammals;
            break;

        case 2:
            selected = birds;
            break;

        case 3:
            selected = fishes;
            break;

        case 4:
            selected = insects;
            break;

        case 5:
            selected = sports;
            break;

        case 6:
            selected = weather;
            break;

        case 7:
            selected = kitchen;
            break;

        case 8:
            selected = fruits;
            break;

        default:
            printf("Invalid level!\n");
            return 0;
    }

    /*
       COPY WORDS INTO LOCAL ARRAYS
    */

    i = 0;

    while(i < 4)
    {
        length = len(selected[i]);

        store(selected[i], words[i], length + 1);
        store(selected[i], answers[i], length + 1);

        i++;
    }

    /*
       START THE GAME
    */

    i = 0;

    while(i < 4)
    {
        length = len(words[i]);

        scramble(words[i], length);

        attempts = 0;
        correct = 0;

        while(attempts < 3 && correct == 0)
        {
            printf("\n========================================\n");
            printf("                 LEVEL %d\n", level);
            printf("========================================\n");

            printf("Scrambled word: %s\n", words[i]);

            printf("Enter your answer: ");
            scanf("%19s", guess);

            /*
               CHECK THE ANSWER
            */

            if(len(guess) == len(answers[i]))
            {
                j = 0;
                correct = 1;

                while(j < length)
                {
                    if(guess[j] != answers[i][j] &&
                       guess[j] != answers[i][j] - ('a' - 'A'))
                    {
                        correct = 0;
                        break;
                    }

                    j++;
                }
            }
            else
            {
                correct = 0;
            }

            if(correct == 1)
            {
                printf("\n");
                printf(makeGreen "CORRECT ANSWER!\n" resetGreen);

                score++;
            }
            else
            {
                attempts++;

                if(attempts < 3)
                {
                    printf("Wrong answer! Try again.\n");
                    printf("Chances remaining: %d\n", 3 - attempts);
                }
                else
                {
                    printf("Out of chances!\n");
                    printf("Correct word: %s\n", answers[i]);
                }
            }
        }

        i++;
    }

    /*
       FINAL RESULT
    */

    printf("\n========================================\n");
    printf("             GAME COMPLETED!\n");
    printf("========================================\n");

    printf("Your score: %d / 4\n", score);

    printf(makeGreen "THANK YOU FOR PLAYING!\n" resetGreen);

    printf("OMM SRI SAI RAM\n");

    return 0;
}
