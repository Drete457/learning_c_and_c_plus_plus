#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "enemy.h"

ENEMY_POSITION enemies;

void allocMemoryEnemy(int numberEnemies)
{
    //sizeof(int/char/double) give us the size in byte we need to that variabel
    //malloc() function to alocat memory dynamic dynamically, don't forget to user free(), to free the memory in use.
    enemies.enemy = malloc(sizeof(int) * numberEnemies);
    for (int i = 0; i < numberEnemies; i++)
    {
        enemies.enemy[i] = malloc(sizeof(int) * 2);
    }
}

void freeMemoryEnemy()
{
    //free the memory in use on enemies
    for (int i = 1; i < enemies.numberOfEnemies; i++)
    {
        free(enemies.enemy[i]);
    }

    free(enemies.enemy);
}

void moveEnemies(GLOBALMAP *graph)
{
    for (int i = 0; i < enemies.numberOfEnemies; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (enemies.enemy[i][0] != 0 && enemies.enemy[i][1] != 0)
            {
                int x = enemies.enemy[i][0];
                int y = enemies.enemy[i][1];

                int direction = chooseDirection();

                switch (direction)
                {
                //UP
                case 0:
                    x--;
                    break;
                //DOWN
                case 2:
                    x++;
                    break;
                //LEFT
                case 1:
                    y--;
                    break;
                //RIGHT
                case 3:
                    y++;
                    break;
                }

                if (!canMove(x, y, i, graph))
                {
                    break;
                }
            }
        }
    }
}

void numberOfEnemies(GLOBALMAP *graph)
{
    int numberEnemies = 0;

    //position of the enemy when the program start
    for (int i = 0; i < graph->mapRows; i++)
    {
        for (int j = 0; j < graph->mapCol; j++)
        {
            if (graph->map[i][j] == ENEMY)
            {
                numberEnemies++;
            }
        }
    }

    allocMemoryEnemy(numberEnemies);
}

void startEnemiesPositions(GLOBALMAP *graph)
{
    numberOfEnemies(graph);

    enemies.numberOfEnemies = 0;

    //position of the enemy when the program start
    for (int i = 0; i < graph->mapRows; i++)
    {
        for (int j = 0; j < graph->mapCol; j++)
        {
            if (graph->map[i][j] == ENEMY)
            {
                enemies.enemy[enemies.numberOfEnemies][0] = i;
                enemies.enemy[enemies.numberOfEnemies][1] = j;
                enemies.numberOfEnemies++;
            }
        }
    }
}

int canMove(int x, int y, int i, GLOBALMAP *graph)
{
    if (!collision(x, y) && !wallVerification(&x, &y, graph))
    {
        graph->map[x][y] = ENEMY;
        graph->map[enemies.enemy[i][0]][enemies.enemy[i][1]] = EMPTY_SPACE;

        enemies.enemy[i][0] = x;
        enemies.enemy[i][1] = y;

        return 0;
    };

    return 1;
}

int chooseDirection()
{
    int segundos = time(0);
    srand(segundos);

    return rand() % 4;
}

int collision(int x, int y)
{
    int hadCollision = 0;

    for (int i = 0; i < enemies.numberOfEnemies; i++)
    {
        if (enemies.enemy[i][0] == x && enemies.enemy[i][1] == y)
        {
            hadCollision = 1;
        }
    }

    return hadCollision;
}

int isEnemy(int xBomb, int yBomb, GLOBALMAP *graph)
{

    if (graph->map[xBomb][yBomb] == ENEMY)
    {
        for (int i = 0; i < enemies.numberOfEnemies; i++)
        {
            if (enemies.enemy[i][0] == xBomb && enemies.enemy[i][1] == yBomb)
            {
                enemies.enemy[i][0] = 0;
                enemies.enemy[i][1] = 0;
            }
        }

        return 0;
    }

    return 1;
}

ENEMY_POSITION getEnemy()
{
    return enemies;
}