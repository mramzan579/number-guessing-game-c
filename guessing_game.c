/*Number Guessing Game 
today added a do-while loop so the player can keep guessing
until they find the secret number.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main(void)
{
    int secret_number;
    int guess;  /* stores what the player types each round */

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

    /* do-while loop: always runs at least once.
       Keeps looping until the player guesses correctly. */
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);  /* read the player's guess */

        //Hints coming in next commit 

    } while (guess != secret_number);  // stop when guess is correct

    //Show success when the loop ends
    printf("\n");
    printf("You got it! Great guess!\n");

    return 0;
}