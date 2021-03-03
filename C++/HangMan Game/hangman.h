#ifndef _HANGMAN_H_
#define _HANGMAN_H_

#include <fstream>
#include <string>
#include <vector>
using namespace std;

void addWordToDB();
void chooseWord();
void endGame();
void intro();
void gameOver();
void drawHangman();
void printTheWord();
void saveTheListOnTheDB(vector<string> fileOfWords);
void wasWrongGuess(char guess);
void winner();
void writeWordToDB();
void wrongGuess();

bool failAllAtteempts();
bool guessedTheWord();
bool wasTheLetter(char guess);

vector<string> readDB();

#endif