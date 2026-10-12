#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

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

    int category = 0;
    int difficulty = 0;
    int maxHints = 0;
    int hintsUsed = 0;
    int choice = 0;
    int i = 0;
    int length = 0;
    int solved = 0;
    int score = 0;

    /* WELCOME SCREEN */

    printf("\n====================================\n");
    printf("          OMM SRI SAI RAM\n");
    printf("           WORD PUZZLE GAME\n");
    printf("====================================\n");

    /* DIFFICULTY SELECTION */

    printf("\nSELECT DIFFICULTY\n");
    printf("1. EASY\n");
    printf("2. MEDIUM\n");
    printf("3. HARD\n");

    printf("\nEnter your choice: ");
    scanf("%d", &difficulty);

    if (difficulty == 1)
    {
        maxHints = 1;
    }
    else if (difficulty == 2)
    {
        maxHints = 2;
    }
    else if (difficulty == 3)
    {
        maxHints = 3;
    }
    else
    {
        printf("\nInvalid difficulty!\n");
        return 0;
    }

    /* CLEAR AFTER DIFFICULTY SELECTION */

    system("clear");

    printf("\n====================================\n");
    printf("          OMM SRI SAI RAM\n");
    printf("====================================\n");

    if (difficulty == 1)
    {
        printf("\nDIFFICULTY: EASY\n");
    }
    else if (difficulty == 2)
    {
        printf("\nDIFFICULTY: MEDIUM\n");
    }
    else
    {
        printf("\nDIFFICULTY: HARD\n");
    }

    /* CATEGORY SELECTION */

    printf("\nSELECT YOUR CATEGORY\n");
    printf("1. Mammals\n");
    printf("2. Birds\n");
    printf("3. Fishes\n");
    printf("4. Insects\n");
    printf("5. Sports\n");
    printf("6. Weather\n");
    printf("7. Kitchen Items\n");
    printf("8. Fruits\n");

    printf("\nEnter your choice: ");
    scanf("%d", &category);

    if (category < 1 || category > 8)
    {
        printf("\nInvalid category!\n");
        return 0;
    }

    /* CLEAR AFTER CATEGORY SELECTION */

    system("clear");

    printf("\n====================================\n");
    printf("          OMM SRI SAI RAM\n");
    printf("====================================\n");

    printf("\nCategory selected: ");

    switch (category)
    {
        case 1:
            printf("Mammals\n");
            break;

        case 2:
            printf("Birds\n");
            break;

        case 3:
            printf("Fishes\n");
            break;

        case 4:
            printf("Insects\n");
            break;

        case 5:
            printf("Sports\n");
            break;

        case 6:
            printf("Weather\n");
            break;

        case 7:
            printf("Kitchen Items\n");
            break;

        case 8:
            printf("Fruits\n");
            break;
    }

    /* COPY SELECTED CATEGORY WORDS */

    i = 0;

    while (i < 4)
    {
        switch (category)
        {
            case 1:
                length = len(mammals[i]);
                store(mammals[i], words[i], length);
                store(mammals[i], answers[i], length);
                break;

            case 2:
                length = len(birds[i]);
                store(birds[i], words[i], length);
                store(birds[i], answers[i], length);
                break;

            case 3:
                length = len(fishes[i]);
                store(fishes[i], words[i], length);
                store(fishes[i], answers[i], length);
                break;

            case 4:
                length = len(insects[i]);
                store(insects[i], words[i], length);
                store(insects[i], answers[i], length);
                break;

            case 5:
                length = len(sports[i]);
                store(sports[i], words[i], length);
                store(sports[i], answers[i], length);
                break;

            case 6:
                length = len(weather[i]);
                store(weather[i], words[i], length);
                store(weather[i], answers[i], length);
                break;

            case 7:
                length = len(kitchen[i]);
                store(kitchen[i], words[i], length);
                store(kitchen[i], answers[i], length);
                break;

            case 8:
                length = len(fruits[i]);
                store(fruits[i], words[i], length);
                store(fruits[i], answers[i], length);
                break;
        }

        i++;
    }

    /* SCRAMBLE ALL FOUR WORDS */

    i = 0;

    while (i < 4)
    {
        length = len(words[i]);
        scramble(words[i], length);
        i++;
    }

    /* CLEAR BEFORE GAME STARTS */

    system("clear");

    printf("\n====================================\n");
    printf("          OMM SRI SAI RAM\n");
    printf("====================================\n");

    printf("\nGAME STARTS!\n");
    printf("Solve all four scrambled words.\n");
    printf("You can request hints according to your difficulty.\n");

    printf("\nPress Enter to continue...");
    getchar();
    getchar();

    /* CLEAR AFTER ENTER */

    system("clear");

    /* PLAY ALL FOUR WORDS */

    i = 0;

    while (i < 4)
    {
        solved = 0;
        hintsUsed = 0;
        guess[0] = '\0';

        length = len(answers[i]);

        /* CLEAR BEFORE EACH NEW WORD */

        system("clear");

        printf("\n====================================\n");
        printf("          OMM SRI SAI RAM\n");
        printf("====================================\n");

        printf("\nWORD %d OF 4\n", i + 1);

        printf("\nDifficulty: ");

        if (difficulty == 1)
        {
            printf("EASY\n");
        }
        else if (difficulty == 2)
        {
            printf("MEDIUM\n");
        }
        else
        {
            printf("HARD\n");
        }

        printf("Score: %d / 4\n", score);

        printf("\nScrambled Word: ");
        printf(makeGreen "%s" resetGreen "\n", words[i]);

        /* GUESS AND HINT LOOP */

        while (solved == 0)
        {
            printf("\n1. Enter your guess\n");
            printf("2. Get a hint\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            /* GUESS */

            if (choice == 1)
            {
                printf("Your guess: ");
                scanf("%19s", guess);

                decapitalize(guess);

                if (len(guess) == length &&
                    isCorrect(answers[i], guess, length))
                {
                    printf(makeGreen "\nCORRECT ANSWER!\n" resetGreen);

                    score++;
                    solved = 1;
                }
                else
                {
                    printf("\nWrong answer! Try again.\n");
                }
            }

            /* HINTS */

            else if (choice == 2)
            {
                if (hintsUsed >= maxHints)
                {
                    printf("\nNo more hints available!\n");
                }
                else
                {
                    hintsUsed++;

                    if (hintsUsed == 1)
                    {
                        printf("\nHINT 1: ");
                        hints_1_2(answers[i], length);
                    }
                    else if (hintsUsed == 2)
                    {
                        printf("\nHINT 2: ");
                        hint3(answers[i], length);
                    }
                    else if (hintsUsed == 3)
                    {
                        printf("\nHINT 3: ");
                        hint4(answers[i], guess, length);
                    }
                }
            }
            else
            {
                printf("\nInvalid choice! Enter 1 or 2.\n");
            }
        }

        printf("\nCorrect word: %s\n", answers[i]);
        printf("Current score: %d / 4\n", score);

        printf("\nPress Enter for the next word...");
        getchar();
        getchar();

        i++;
    }

    /* FINAL RESULT */

    system("clear");

    printf("\n====================================\n");
    printf("          OMM SRI SAI RAM\n");
    printf("====================================\n");

    printf("\n          GAME COMPLETED!\n");

    printf("\nFinal score: %d / 4\n", score);

    if (score == 4)
    {
        printf("\nExcellent! You solved every word!\n");
    }
    else if (score >= 2)
    {
        printf("\nGood job! Keep practising!\n");
    }
    else
    {
        printf("\nKeep trying! You will improve!\n");
    }

    printf("\nOMM SRI SAI RAM\n");

    return 0;
}
