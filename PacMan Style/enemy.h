#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "map.h"

//Const Global variables
#define ENEMY 'F'

//create a group of variabels
struct enemysPositions
{
    int **enemy;
    int numberOfEnemies;
};

//create a typedef struct of globalMap with the name GLOBALMAP
typedef struct enemysPositions ENEMY_POSITION;

void allocMemoryEnemy(int numberEnemies);
void freeMemoryEnemy();
void moveEnemies(GLOBALMAP *graph);
void numberOfEnemies(GLOBALMAP *graph);
void startEnemiesPositions(GLOBALMAP *graph);

int canMove(int x, int y, int i, GLOBALMAP *graph);
int chooseDirection();
int collision(int x, int y);
int isEnemy(int xBomb, int yBomb, GLOBALMAP *graph);

ENEMY_POSITION getEnemy();

#endif