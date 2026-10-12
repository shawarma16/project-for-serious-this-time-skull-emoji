#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main()
{
    srand(time(NULL));

    char mammals[4][20] = {"dolphin","kangaroo","cheetah","gorilla"};
    char birds[4][20] = {"flamingo","ostrich","peacock","penguin"};
    char fishes[4][20] = {"salmon","catfish","sardine","goldfish"};
    char insects[4][20] = {"beetle","spider","cicada","cricket"};
    char sports[4][20] = {"football","tennis","hockey","curling"};
    char weather[4][20] = {"breeze","thunder","blizzard","tornado"};
    char kitchen[4][20] = {"blender","toaster","spatula","grater"};
    char fruits[4][20] = {"banana","cherry","orange","avocado"};

    char words[4][20], answers[4][20], guess[20];

    int category = 0, difficulty = 0, maxHints = 0;
    int choice, i, j, length, attempts, hintsUsed;
    int solved, score = 0;

    /* WELCOME SCREEN */

    printf("\n===== OMM SRI SAI RAM =====\n");
    printf("       WORD PUZZLE\n\n");

    /* DIFFICULTY SELECTION */

    while (difficulty < 1 || difficulty > 3)
    {
        printf("\n%s%s EASY %s (1 hint)\n",
               easyBg, textBlack, textColourReset);

        printf("%s%s MEDIUM %s (2 hints)\n",
               mediumBg, textBlack, textColourReset);

        printf("%s%s HARD %s (3 hints)\n",
               hardBg, textBlack, textColourReset);

        printf("Choose difficulty (1-3): ");

        if (scanf("%d", &difficulty) != 1)
        {
            while (getchar() != '\n')
                ;

            difficulty = 0;
            printf("Invalid input! Enter a number.\n");
        }
    }

    maxHints = difficulty;

    system("clear");

    /* CATEGORY SELECTION */

    printf("===== SELECT CATEGORY =====\n");
    printf("1. Mammals   2. Birds    3. Fishes   4. Insects\n");
    printf("5. Sports    6. Weather  7. Kitchen  8. Fruits\n");

    while (category < 1 || category > 8)
    {
        printf("\nChoose category (1-8): ");

        if (scanf("%d", &category) != 1)
        {
            while (getchar() != '\n')
                ;

            category = 0;
            printf("Invalid input! Enter a number.\n");
        }
    }

    system("clear");

    /* COPY CATEGORY WORDS */

    i = 0;

    while (i < 4)
    {
        switch (category)
        {
            case 1:
                store(mammals[i], words[i], len(mammals[i]));
                store(mammals[i], answers[i], len(mammals[i]));
                break;

            case 2:
                store(birds[i], words[i], len(birds[i]));
                store(birds[i], answers[i], len(birds[i]));
                break;

            case 3:
                store(fishes[i], words[i], len(fishes[i]));
                store(fishes[i], answers[i], len(fishes[i]));
                break;

            case 4:
                store(insects[i], words[i], len(insects[i]));
                store(insects[i], answers[i], len(insects[i]));
                break;

            case 5:
                store(sports[i], words[i], len(sports[i]));
                store(sports[i], answers[i], len(sports[i]));
                break;

            case 6:
                store(weather[i], words[i], len(weather[i]));
                store(weather[i], answers[i], len(weather[i]));
                break;

            case 7:
                store(kitchen[i], words[i], len(kitchen[i]));
                store(kitchen[i], answers[i], len(kitchen[i]));
                break;

            case 8:
                store(fruits[i], words[i], len(fruits[i]));
                store(fruits[i], answers[i], len(fruits[i]));
                break;
        }

        scramble(words[i], len(words[i]));
        i++;
    }

    /* GAME INTRODUCTION */

    system("clear");

    printf("===== GAME STARTS =====\n");
    printf("3 chances per word.\n");
    printf("Hints do not consume guessing chances.\n");
    printf("\nPress Enter to play...");

    getchar();
    getchar();

    /* GAME LOOP */

    i = 0;

    while (i < 4)
    {
        system("clear");

        attempts = 0;
        hintsUsed = 0;
        solved = 0;
        length = len(answers[i]);

        j = 0;

        while (j < 20)
        {
            guess[j] = '\0';
            j++;
        }

        printf("===== OMM SRI SAI RAM =====\n");
        printf("WORD %d / 4\n", i + 1);
        printf("Score: %d / 4\n", score);

        /* DIFFICULTY COLOUR */

        if (difficulty == 1)
            printf("%s%s EASY %s\n",
                   easyBg, textBlack, textColourReset);

        else if (difficulty == 2)
            printf("%s%s MEDIUM %s\n",
                   mediumBg, textBlack, textColourReset);

        else
            printf("%s%s HARD %s\n",
                   hardBg, textBlack, textColourReset);

        printf("\nScrambled word: ");
        printf(makeGreen "%s" resetGreen "\n", words[i]);

        /* GUESS AND HINT LOOP */

        while (solved == 0 && attempts < 3)
        {
            printf("\nChances left: %d\n", 3 - attempts);
            printf("1. Guess   2. Hint\n");
            printf("Choice: ");

            if (scanf("%d", &choice) != 1)
            {
                while (getchar() != '\n')
                    ;

                printf("Invalid input! Enter 1 or 2.\n");
                continue;
            }

            /* GUESS */

            if (choice == 1)
            {
                printf("Your guess: ");

                if (scanf("%19s", guess) != 1)
                {
                    while (getchar() != '\n')
                        ;

                    printf("Invalid input! Try again.\n");
                    continue;
                }

                while (getchar() != '\n')
                    ;

                decapitalize(guess);
                attempts++;

                if (len(guess) == length &&
                    isCorrect(answers[i], guess, length))
                {
                    printf(makeGreen "\nCORRECT!\n" resetGreen);

                    score++;
                    solved = 1;
                }
                else
                {
                    printf("\nWrong guess!\n");
                }
            }

            /* HINTS */

            else if (choice == 2)
            {
                if (hintsUsed >= maxHints)
                {
                    printf("\nNo hints left!\n");
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

        /* SHOW CORRECT ANSWER IF CHANCES END */

        if (solved == 0)
        {
            printf("\nOut of chances!\n");

            printf("The correct answer was: ");
            printf(makeGreen "%s" resetGreen "\n", answers[i]);
        }

        printf("\nScore: %d / 4\n", score);
        printf("Press Enter for the next word...");

        getchar();

        i++;
    }

    /* FINAL RESULT */

    system("clear");

    printf("===== GAME COMPLETED =====\n");
    printf("Final score: %d / 4\n", score);

    if (score == 4)
        printf("Excellent! All words solved!\n");

    else if (score >= 2)
        printf("Good job! Keep practising!\n");

    else
        printf("Keep trying!\n");

    printf("\nOMM SRI SAI RAM\n");

    return 0;
}
