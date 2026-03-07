//Number Guessing Game
#include <stdio.h>

//Define the range of the secret number in one place.
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main(void)
{
    /* Print welcome banner showing the number range */
    printf("========================================\n");
    printf("       NUMBER GUESSING GAME             \n");
    printf("========================================\n");
    printf("\n");
    printf("I have picked a secret number between %d and %d.\n",
           MIN_NUMBER, MAX_NUMBER);
    printf("Can you guess it?\n");
    printf("\n");

    return 0;
}