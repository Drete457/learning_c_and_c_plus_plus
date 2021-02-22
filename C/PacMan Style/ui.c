#include <stdio.h>
#include "map.h"
#include "enemy.h"
#include "ui.h"

char enemyUI[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char wallUI[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char heroUI[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char bombUI[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};

char emptySpaceUI[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

void printUi(char draw[4][7], int part)
{
    printf("%s", draw[part]);
}

void showUI(GLOBALMAP *graph, int row, int part, int col)
{
    switch (graph->map[row][col])
    {
    case ENEMY:
        printUi(enemyUI, part);
        break;
    case HERO:
        printUi(heroUI, part);
        break;
    case BOMB:
        printUi(bombUI, part);
        break;
    case STANDING_WALL:
    case LYING_WALL:
        printUi(wallUI, part);
        break;
    case EMPTY_SPACE:
        printUi(emptySpaceUI, part);
        break;
    }
}