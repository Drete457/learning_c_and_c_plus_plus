#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "enemy.h"
#include "run.h"

GLOBALMAP graph;

void wellcomeMessage()
{
    printf("************************************\n");
    printf("*          PacMan Style            *\n");
    printf("*       a - left, d - right        *\n");
    printf("*       w - up,   s - down         *\n");
    printf("*      b - explode the Bomb        *\n");
    printf("* Note: The Enemy can eat the bomb *\n");
    printf("************************************\n\n");
}

void lose()
{
    printf("\nYou Died!\n");

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

void winMessage()
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

int finish()
{
    ENEMY_POSITION enemies = getEnemy();
    HEROPOSITION hero = getHero();

    int enemiesDied = enemies.numberOfEnemies;

    for (int i = 0; i < enemies.numberOfEnemies; i++)
    {
        if (hero.xInit == enemies.enemy[i][0] && hero.yInit == enemies.enemy[i][1])
        {
            lose();
            exit(1);
        }

        if (enemies.enemy[i][0] == 0 && enemies.enemy[i][1] == 0)
        {
            enemiesDied--;
        }
    }

    if (enemiesDied == 0)

    {
        return 1;
    }

    return 0;
}

int main()
{
    readMap(&graph);
    startHeroPosition(&graph);
    startEnemiesPositions(&graph);

    wellcomeMessage();

    do
    {
        showMap(&graph);

        char arrowKey;
        scanf(" %c", &arrowKey);

        moveEnemies(&graph);
        move(arrowKey, &graph);

    } while (!finish());

    winMessage();

    freeMemory(&graph);
    freeMemoryEnemy();
}