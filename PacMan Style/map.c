#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "ui.h"
#include "map.h"

//Note: (*struct).variabel name is the make thin write struct name -> variabel name
HEROPOSITION position;
BOMBAREA bombArea[8] = {{-1, -1}, {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}, {+1, -1}, {0, -1}};

int haveBomb = 0;

void allocMemory(GLOBALMAP *graph)
{
    //sizeof(int/char/double) give us the size in byte we need to that variabel
    //malloc() function to alocat memory dynamic dynamically, don't forget to user free(), to free the memory in use.
    graph->map = malloc(sizeof(char) * graph->mapRows);
    for (int i = 0; i < graph->mapRows; i++)
    {
        graph->map[i] = malloc(sizeof(char) * (graph->mapCol + COL_AND_ZERO));
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

void explodeBomb(GLOBALMAP *graph)
{
    if (haveBomb > 0)
    {
        int bombAreaArraySize = sizeof(bombArea) / sizeof(int);

        for (int i = 0; i < bombAreaArraySize / 2; i++)
        {
            int xBomb = position.xInit + bombArea[i].x;
            int yBomb = position.yInit + bombArea[i].y;

            if (!isEnemy(xBomb, yBomb, graph))
            {
                graph->map[xBomb][yBomb] = EMPTY_SPACE;
            }
        }

        haveBomb--;
    }
}

void freeMemory(GLOBALMAP *graph)
{
    //free the memory in use on mapSize
    for (int i = 1; i < graph->mapRows; i++)
    {
        free(graph->map[i]);
    }

    free(graph->map);
}

void isBomb(int x, int y, GLOBALMAP *graph)
{
    if (graph->map[x][y] == BOMB)
    {
        haveBomb++;
    }
}

void isWall(int xFinal, int yFinal, GLOBALMAP *graph)
{
    //verify if the next direction is a wall
    if (!wallVerification(&xFinal, &yFinal, graph))
    {
        graph->map[position.xInit][position.yInit] = EMPTY_SPACE;

        graph->map[xFinal][yFinal] = HERO;

        position.xInit = xFinal;
        position.yInit = yFinal;
    }
}

void move(char direction, GLOBALMAP *graph)
{
    int xFinal;
    int yFinal;

    xFinal = position.xInit;
    yFinal = position.yInit;

    switch (direction)
    {
    case UP:
        xFinal--;
        break;
    case DOWN:
        xFinal++;
        break;
    case LEFT:
        yFinal--;
        break;
    case RIGHT:
        yFinal++;
        break;
    case BOMB_EXPLOSION:
        explodeBomb(graph);
        break;
    }

    isBomb(xFinal, yFinal, graph);
    isWall(xFinal, yFinal, graph);
}

void readMap(GLOBALMAP *graph)
{
    FILE *f;

    //open the file and verify if variabel f have a file open
    f = fopen("map.txt", "r");
    checkFileOpen(f);

    fscanf(f, "%d %d", &graph->mapRows, &graph->mapCol);

    allocMemory(graph);

    //put the map on the memory
    for (int i = 0; i < graph->mapRows; i++)
    {
        fscanf(f, "%s", graph->map[i]);
    }

    fclose(f);
}

void startHeroPosition(GLOBALMAP *graph)
{
    //position of the user @ when the program start
    for (int i = 0; i < graph->mapRows; i++)
    {
        for (int j = 0; j < graph->mapCol; j++)
        {
            if (graph->map[i][j] == HERO)
            {
                position.xInit = i;
                position.yInit = j;
                break;
            }
        }
    }
}

void showMap(GLOBALMAP *graph)
{
    printf("You have %d bombs to use \n", haveBomb);
    for (int row = 0; row < graph->mapRows; row++)
    {
        for (int part = 0; part < 4; part++)
        {
            for (int col = 0; col < graph->mapCol; col++)
            {
                showUI(graph, row, part, col);
            }
            printf("\n");
        }   
    }
}

int wallVerification(int *x, int *y, GLOBALMAP *graph)
{
    if (graph->map[(*x)][(*y)] == STANDING_WALL || graph->map[(*x)][(*y)] == LYING_WALL)
    {
        return 1;
    }

    return 0;
}

HEROPOSITION getHero()
{
    return position;
}