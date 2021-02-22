#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

//Global variables
char secretWord[WORD_SIZE];
char guess[26];
int attempts = 0;

void addWord()
{
    char choose;

    printf("Do you want to add a new word in the game? (Y/N)\n");
    scanf(" %c", &choose);

    if (choose == 'Y')
    {
        char newWord[WORD_SIZE];

        printf("What is the new word?\n");
        scanf(" %s", &newWord);

        //r+ is to read and write
        FILE *f;
        f = fopen("words.txt", "r+");

        //will check whether the file exists or not and whether it was opened or not
        checkFileOpen(f);

        //will read the number of words and rewrite with the new number
        int amount;
        fscanf(f, "%d", &amount);
        amount++;

        //go to the arrow of the file at the beginning.
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", amount);

        //go by the arrow at the end and write the new word
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", newWord);

        fclose(f);
    }
}

void checkFileOpen(FILE *f)
{
    if (f == 0)
    {
        printf("Database is not accessible\n\n");
        exit(1);
    }
}

void chooseWord()
{
    FILE *f;

    // r to read
    f = fopen("words.txt", "r");

    //will check whether the file exists or not and whether it was opened or not
    checkFileOpen(f);

    //read the first line of the file
    int manyLines;
    fscanf(f, "%d", &manyLines);

    srand(time(0));
    int line = rand() % manyLines;

    //It will go line by line until you reach the chosen line
    for (int i = 1; i < line; i++)
    {
        fscanf(f, "%s", &secretWord);
    }

    fclose(f);
}

void drawHanged()
{
    int head = NUMBER_OF_ATTEMPTS / NUMBER_OF_ATTEMPTS;
    int body = NUMBER_OF_ATTEMPTS * 0.30;
    int arms = NUMBER_OF_ATTEMPTS * 0.60;
    int legs = NUMBER_OF_ATTEMPTS * 0.90;

    int errors = kicksError();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (errors >= head ? '(' : ' '), (errors >= head ? '_' : ' '), (errors >= head ? ')' : ' '));
    printf(" |      %c%c%c  \n", (errors >= arms ? '\\' : ' '), (errors >= body ? '|' : ' '), (errors >= arms ? '/' : ' '));
    printf(" |       %c     \n", (errors >= body ? '|' : ' '));
    printf(" |      %c %c   \n", (errors >= legs ? '/' : ' '), (errors >= legs ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    //strlen gives the total size, end when it finds \ 0
    for (int i = 0; i < strlen(secretWord); i++)
    {

        int find = alreadyKicked(secretWord[i]);

        resultWord(find, secretWord[i]);
    }

    printf("\n");
}

void guessWhat()
{
    //the space between " %c", tells the program to ignore "enter"
    char hit;
    printf("Which letter? ");
    scanf(" %c", &hit);

    //so it resolves the address to the value with (* variable), without () if only * variable, reads the value without problems
    guess[attempts] = hit;
    attempts++;
}

void opening()
{
    printf("**********************************\n");
    printf("*          Hangman game          *\n");
    printf("**********************************\n\n");
}

void lose()
{
    printf("\nGosh, you were hanged!\n");
    printf("The word was **%s**\n\n", secretWord);

    printf("    _______________         \n");
    printf("   /               \\       \n");
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");
}

void resultWord(int find, char letter)
{
    if (find)
    {
        printf("%c ", letter);
    }
    else
    {
        printf("_ ");
    }
}

void win()
{
    printf("\nCongratulation, you won!\n\n");

    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
}

int alreadyKicked(char letter)
{
    for (int j = 0; j < attempts; j++)
    {
        if (guess[j] == letter)
        {
            return 1;
        }
    }

    return 0;
}

int hanged()
{
    return kicksError() >= NUMBER_OF_ATTEMPTS;
}

int kicksError()
{
    int errors = 0;

    for (int i = 0; i < attempts; i++)
    {
        int exists = 0;

        for (int j = 0; j < strlen(secretWord); j++)
        {
            exists = alreadyKicked(secretWord[i]);
        }

        if (!exists)
        {
            errors++;
        }
    }

    return errors;
}

int youGotIt()
{
    for (int i = 0; i < strlen(secretWord); i++)
    {
        if (!alreadyKicked(secretWord[i]))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    chooseWord();
    opening();

    do
    {

        drawHanged();
        guessWhat();

    } while (!youGotIt() && !hanged());

    if (youGotIt())
    {
        win();
    }
    else
    {
        lose();
    }

    addWord();
}
