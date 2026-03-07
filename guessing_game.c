// Number Guessing Game - Initial Version

#include <stdio.h>
#include <stdlib.h>  // needed for rand() and srand()
#include <time.h>    //needed for time()

#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main(void)
{
    /* This variable will hold the secret number */
    int secret_number;

    /* Seed the random number generator with current time.
       Without this, the game would pick the same number every run. */
    srand((unsigned int)time(NULL));

    /* Generate a number between MIN_NUMBER and MAX_NUMBER.
       rand() % MAX_NUMBER gives us 0 to 99.
       Adding MIN_NUMBER shifts it to 1 to 100. */
    secret_number = (rand() % MAX_NUMBER) + MIN_NUMBER;

    /* Welcome banner */
    printf("========================================\n");
    printf("       NUMBER GUESSING GAME             \n");
    printf("========================================\n");
    printf("\n");
    printf("I have picked a secret number between %d and %d.\n",
           MIN_NUMBER, MAX_NUMBER);
    printf("Can you guess it?\n");
    printf("\n");

    /* Temporary: show secret number while testing.
       We will remove this line in the next commit. */
    printf("[DEBUG] Secret number is: %d\n", secret_number);

    return 0;
}