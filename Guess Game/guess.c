#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

printf("          P  /_\\  P                               \n");
printf("         /_\\_|_|_/_\\                             \n");
printf("     n_n | ||. .|| | n_n         Welcome to        \n");
printf("     |_|_|nnnn nnnn|_|_|     our guessing game!    \n");
printf("    |" "  |  |_|  |  " "|                          \n");
printf("    |_____| ' _ ' |_____|                          \n");
printf("          \\__|_|__/                               \n\n");

int level;
printf("What is the level of difficulty? \n");
printf("(1) Easy (2) Medium (3) Difficult \n\n");
printf("Choice: ");
scanf("%d", &level);

int sec = time(0);
srand(sec);

int secreatNumber = rand() % 100;

int guess;
int numberOfAttempts;

switch (level)
{
case 1:
    numberOfAttempts = 20;
    break;
case 2:
    numberOfAttempts = 15;
    break;
default:
    numberOfAttempts = 10;
    break;
}
  

    double points = 1000;

    for (int i = numberOfAttempts; i >= 1; i--)
    {
        printf("What's your kick? ");
        scanf("%d", &guess);

        if (guess < 0)
        {
            printf("You can't kick negative numbers ");

            continue;
        }

        int hit = (guess == secreatNumber);
        int bigger = guess > secreatNumber;

        if (hit)
        {
            printf("Congratulations! You're right!\n");
            printf("Play again, you are a good player!\n");

            printf("\n\n");
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n\n");

            break;
        }

        else if (bigger)
        {
            printf("The number chosen is greater than the secret number \n");
        }

        else
        {
            printf("The number chosen is less than the secret number \n");
        }

        numberOfAttempts++;

        double pointsLost = (guess - secreatNumber) / (double)2;

        points = points - abs(pointsLost);
    }

    printf("Total of points: %.2f \n", points);
    printf("Thanks for playing!\n");
}
