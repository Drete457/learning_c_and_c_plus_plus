#ifndef _MAP_H_
#define _MAP_H_

//Const Global variables
//   COL_AND_ZERO = "\0"
#define COL_AND_ZERO 1

#define STANDING_WALL '|'
#define LYING_WALL '-'
#define EMPTY_SPACE '.'
#define BOMB 'P'

#define HERO '@'

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define BOMB_EXPLOSION 'b'

//create a group of variabels
struct globalMap
{
    //Global variables
    //Store the Map
    int mapRows;
    int mapCol;
    char **map;
};

struct heroPosition
{
    int xInit;
    int yInit;
};

struct bombArea
{
    int x;
    int y;
};

//create a typedef struct of globalMap with the name GLOBALMAP
typedef struct globalMap GLOBALMAP;
typedef struct heroPosition HEROPOSITION;
typedef struct bombArea BOMBAREA;

void allocMemory(GLOBALMAP *graph);
void checkFileOpen(FILE *f);
void explodeBomb(GLOBALMAP *graph);
void freeMemory(GLOBALMAP *graph);
void isBomb(int x, int y, GLOBALMAP *graph);
void isWall(int xFinal, int yFinal, GLOBALMAP *graph);
void move(char direction, GLOBALMAP *graph);
void readMap(GLOBALMAP *graph);
void startHeroPosition(GLOBALMAP *graph);
void showMap(GLOBALMAP *graph);

int wallVerification(int *x, int *y, GLOBALMAP *graph);

HEROPOSITION getHero();

#endif