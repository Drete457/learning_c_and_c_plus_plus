//constant global variable
#define NUMBER_OF_ATTEMPTS 10
#define WORD_SIZE 20

//Allows the copier to know all the functions that will exist in the program and before he reaches the function
void addWord();
void checkFileOpen(FILE* f); 
void chooseWord();
void drawHanged();
void guessWhat();
void opening();
void lose();
void resultWord(int find, char letter);
void win();

int alreadyKicked(char letter);
int hanged();
int kicksError();
int youGotIt();