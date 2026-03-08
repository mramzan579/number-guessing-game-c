/*
 * guessing_game.c
 * Number Guessing Game with Input Validation
 * Validate all user input. Reject letters, symbols,
 * and numbers outside the valid range.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

/* 
   clear_input_buffer()
   After a bad scanf, leftover characters stay in the input
   stream and cause an infinite loop. This function removes
   them so the player can try again cleanly. */
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/*
   get_valid_guess()
   Keeps asking until the player enters a proper integer
   that falls within MIN_NUMBER to MAX_NUMBER.
   Returns the valid guess.*/
int get_valid_guess(void)
{
    int guess;
    int scan_result;

    while (1) {  //loop forever until user enters a valid input
        printf("Enter your guess: ");
        scan_result = scanf("%d", &guess);

        if (scan_result != 1) {
            /* Player typed something that is not a number */
            clear_input_buffer();
            printf("  Invalid input! Please type a whole number.\n\n");
            continue;  /* go back to the top of the loop */
        }

        /* Input was a number — now check the range */
        clear_input_buffer();

        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("  Out of range! Enter a number between %d and %d.\n\n",
                   MIN_NUMBER, MAX_NUMBER);
            continue;
        }

        // If user reaches here, the input is valid — return it 
        return guess;
    }
}

/* -------------------------------------------------------
   main()
------------------------------------------------------- */
int main(void)
{
    int secret_number;
    int guess;
    int attempts = 0;

    // Seed and generate secret number
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

    /* Guessing loop — now uses validated input */
    do {
        guess = get_valid_guess();  /* safe, validated input */
        attempts++;

        if (guess < secret_number) {
            printf("  Too low!  The number is higher.\n\n");
        } else if (guess > secret_number) {
            printf("  Too high! The number is lower.\n\n");
        }

    } while (guess != secret_number);

    /* Success message */
    printf("\n========================================\n");
    printf("  Correct! The number was %d.\n", secret_number);
    printf("========================================\n");

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