/*
 * Number Guessing Game 
 * in this commit given directional hints 
 * to player after each wrong guess.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main(void)
{
    int secret_number;
    int guess;

    /* Seed and generate secret number */
    srand((unsigned int)time(NULL));
    secret_number = (rand() % MAX_NUMBER) + MIN_NUMBER;

    //Welcome banner
    printf("========================================\n");
    printf("       NUMBER GUESSING GAME             \n");
    printf("========================================\n");
    printf("\n");
    printf("I have picked a secret number between %d and %d.\n",
           MIN_NUMBER, MAX_NUMBER);
    printf("Can you guess it?\n");
    printf("\n");

    //Guessing loop with directional hints
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        /* Compare the guess to the secret number and give a hint */
        if (guess < secret_number) {
            //Player guessed too small
            printf("  Too low!  The number is higher.\n\n");
        } else if (guess > secret_number) {
            //Player guessed too large
            printf("  Too high! The number is lower.\n\n");
        }
        /* If neither, guess == secret_number and the loop will end */

    } while (guess != secret_number);

    //Success
    printf("Correct! You found the number!\n");

    return 0;
}