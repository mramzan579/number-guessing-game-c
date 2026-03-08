/*
 * guessing_game.c
 *
 * A console-based number guessing game written in C.
 * The computer picks a random number between 1 and 100.
 * The player guesses until they find it, with hints along the way.
 *
 * Compile : gcc guessing_game.c -o guessing_game
 * Run     : ./guessing_game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Game constants
#define MIN_NUMBER 1
#define MAX_NUMBER 100

/* -------------------------------------------------------
   clear_input_buffer()
   Drains leftover characters from stdin after bad input.
------------------------------------------------------- */
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* -------------------------------------------------------
   get_valid_guess()
   Loops until the player enters a valid integer
   between MIN_NUMBER and MAX_NUMBER. Returns the value.
------------------------------------------------------- */
int get_valid_guess(void)
{
    int guess;
    int scan_result;

    while (1) {
        printf("Enter your guess: ");
        scan_result = scanf("%d", &guess);

        if (scan_result != 1) {
            clear_input_buffer();
            printf("  Invalid input! Please type a whole number.\n\n");
            continue;
        }

        clear_input_buffer();

        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("  Out of range! Enter a number between %d and %d.\n\n",
                   MIN_NUMBER, MAX_NUMBER);
            continue;
        }

        return guess;
    }
}

/* -------------------------------------------------------
   ask_play_again()
   Asks if the player wants another round.
   Returns 1 for yes, 0 for no.
------------------------------------------------------- */
int ask_play_again(void)
{
    char choice;

    while (1) {
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &choice);  // space before %c skips whitespace 
        clear_input_buffer();

        if (choice == 'y' || choice == 'Y') {
            return 1;  /* yes, play again */
        } else if (choice == 'n' || choice == 'N') {
            return 0;  /* no, quit */
        } else {
            printf("  Please enter y or n.\n");
        }
    }
}

/* -------------------------------------------------------
   play_one_game()
   Runs a single full round of the guessing game.
   Returns the number of attempts the player used.
------------------------------------------------------- */
int play_one_game(void)
{
    int secret_number;
    int guess;
    int attempts = 0;

    //Generate a new secret number for this round 
    secret_number = (rand() % MAX_NUMBER) + MIN_NUMBER;

    printf("\nI have picked a secret number between %d and %d.\n",
           MIN_NUMBER, MAX_NUMBER);
    printf("Can you guess it?\n\n");

    //Guessing loop
    do {
        guess = get_valid_guess();
        attempts++;

        if (guess < secret_number) {
            printf("  Too low!  The number is higher.\n\n");
        } else if (guess > secret_number) {
            printf("  Too high! The number is lower.\n\n");
        }

    } while (guess != secret_number);

    /* Win message */
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

    return attempts;
}

/* -------------------------------------------------------
   main()
   Seeds the PRNG once, then runs rounds until the
   player decides to quit. Tracks best score overall.
------------------------------------------------------- */
int main(void)
{
    int round      = 1;  /* current round number        */
    int last_score = 0;  /* attempts used in last round */
    int best_score = 0;  /* fewest attempts across all rounds */

    /* Seed once at the start — not inside the game loop */
    srand((unsigned int)time(NULL));

    /* Welcome banner */
    printf("========================================\n");
    printf("       NUMBER GUESSING GAME             \n");
    printf("========================================\n");

    /* Main play-again loop */
    do {
        printf("\n--- Round %d ---\n", round);

        last_score = play_one_game();

        /* Update best score if this round was better */
        if (best_score == 0 || last_score < best_score) {
            best_score = last_score;
        }

        round++;

    } while (ask_play_again());

    /* Final summary */
    printf("\n========================================\n");
    printf("  Thanks for playing!\n");
    printf("  Rounds played : %d\n", round - 1);
    printf("  Best score    : %d guess(es)\n", best_score);
    printf("========================================\n");
    printf("Goodbye! Come back and beat your record.\n\n");

    return 0;
}
