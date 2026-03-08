/*
 * guessing_game.c
 * Number Guessing Game — 
 * Count how many guesses the player takes and
 * show a different message based on performance.
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
    int attempts = 0;  /* starts at 0, goes up by 1 each guess */

    /* Seed and generate secret number */
    srand((unsigned int)time(NULL));
    secret_number = (rand() % MAX_NUMBER) + MIN_NUMBER;

    // Welcome banner 
    printf("========================================\n");
    printf("       NUMBER GUESSING GAME             \n");
    printf("========================================\n");
    printf("\n");
    printf("I have picked a secret number between %d and %d.\n",
           MIN_NUMBER, MAX_NUMBER);
    printf("Can you guess it?\n");
    printf("\n");

    //Guessing loop
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;  //count this guess regardless of right or wrong

        if (guess < secret_number) {
            printf("  Too low!  The number is higher.\n\n");
        } else if (guess > secret_number) {
            printf("  Too high! The number is lower.\n\n");
        }

    } while (guess != secret_number);

    //Show the correct number
    printf("\n========================================\n");
    printf("  Correct! The number was %d.\n", secret_number);
    printf("========================================\n");

    //Tiered praise based on number of attempts
    if (attempts == 1) {
        printf("PERFECT! First guess! Unbelievable!\n");
    } else if (attempts <= 5) {
        printf("Excellent! You did it in just %d guesses!\n", attempts);
    } else if (attempts <= 10) {
        printf("Good job! It took you %d guesses.\n", attempts);
    } else {
        printf("You made it! Total guesses: %d. Keep practicing!\n", attempts);
    }

    return 0;
}