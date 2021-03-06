#include <cstdlib>
#include <ctime>
#include <iostream>
//have the ifstream type
#include <fstream>
//have the map type
#include <map>
//have the string type
#include <string>
//have the vector type
#include <vector>

#include "hangman.h"
using namespace std;

string secretWord;
int numberOfTries = 6;
//creates a map that receives some format and returns another format
map<char, bool> guestAttempts;
vector<char> guestWrong;

void addWordToDB()
{
    char answer;
    cout << "Do you want to add a new word in the game? (Y/N)" << endl;
    cin >> answer;

    if (answer == 'Y')
    {
        writeWordToDB();
    }
}

void chooseWord()
{
    vector<string> fileOfWords = readDB();

    srand(time(NULL));
    const int chooseWord = rand() % fileOfWords.size();

    secretWord = fileOfWords[chooseWord];
}

void endGame()
{
    if (!failAllAtteempts())
    {
        gameOver();
    }
    else
    {
        winner();
        addWordToDB();
    }
}

void intro()
{
    cout << "******************************************" << endl;
    cout << "*      Welcome to our Hangman game!      *" << endl;
    cout << "******************************************" << endl;
    cout << "   Note: Letters need to be in Uppercase  " << endl;
    cout << endl;
}

void gameOver()
{
    cout << "Gosh, you were hanged!" << endl;

    cout << "    _______________         " << endl;
    cout << "   /               \\       " << endl;
    cout << "  /                 \\      " << endl;
    cout << "//                   \\/\\  " << endl;
    cout << "\\|   XXXX     XXXX   | /   " << endl;
    cout << " |   XXXX     XXXX   |/     " << endl;
    cout << " |   XXX       XXX   |      " << endl;
    cout << " |                   |      " << endl;
    cout << " \\__      XXX      __/     " << endl;
    cout << "   |\\     XXX     /|       " << endl;
    cout << "   | |           | |        " << endl;
    cout << "   | I I I I I I I |        " << endl;
    cout << "   |  I I I I I I  |        " << endl;
    cout << "   \\_             _/       " << endl;
    cout << "     \\_         _/         " << endl;
    cout << "       \\_______/           " << endl;
}

void drawHangman()
{
        int head = numberOfTries / numberOfTries;
        int body = numberOfTries * 0.30;
        int arms = numberOfTries * 0.60;
        int legs = numberOfTries * 0.90;

        int errors = guestWrong.size();

        cout << "  _______       " << endl;
        cout << " |/      |      " << endl;
        cout << " |      " << (errors >= head ? '(' : ' ') << (errors >= head ? '_' : ' ') << (errors >= head ? ')' : ' ') << endl;
        cout << " |      " << (errors >= arms ? '\\' : ' ') << (errors >= body ? '|' : ' ') << (errors >= arms ? '/' : ' ') << endl;
        cout << " |       " << (errors >= body ? '|' : ' ') << endl;
        cout << " |      " << (errors >= legs ? '/' : ' ') << (errors >= legs ? (char)39 : ' ') << (errors >= legs ? '\\' : ' ') << endl;
        cout << " |              " << endl;
        cout << "_|___           " << endl;
        cout << endl;
}

void printTheWord()
{
    //we can user the proprity size() to know the size of the word for the for or use this for to make the same thing. ex: for (int i = 0; i < SECRET_WORD.size() ; i++){}
    for (char letter : secretWord)
    {
        bool letterWasChoose = guestAttempts[letter];

        if (letterWasChoose)
        {
            cout << letter << " ";
        }
        else
        {
            cout << "_ ";
        }
    }

    cout << endl;
}

void saveTheListOnTheDB(vector<string> newList)
{
    ofstream file;
    file.open("words.txt");

    if (file.is_open())
    {
        file << newList.size() << endl;

        for (string word : newList)
        {
            file << word << endl;
        }

        file.close();

        cout << "Word Successfully Added" << endl;
    }
    else
    {
        cout << "Database is not accessible!" << endl;
    }
}

void wasWrongGuess(char guess)
{
    bool haveTheLetter = wasTheLetter(guess);
    guestAttempts[guess] = true;

    if (haveTheLetter)
    {
        cout << "Your guess was correct" << endl;
    }
    else
    {
        cout << "Your guess was incorrect" << endl;
        guestWrong.push_back(guess);
    }

    cout << endl;
}

void winner()
{
    cout << " Congratulation, you won! " << endl;

    cout << "       ___________      " << endl;
    cout << "      '._==_==_=_.'     " << endl;
    cout << "      .-\\:      /-.    " << endl;
    cout << "     | (|:.     |) |    " << endl;
    cout << "      '-|:.     |-'     " << endl;
    cout << "        \\::.    /      " << endl;
    cout << "         '::. .'        " << endl;
    cout << "           ) (          " << endl;
    cout << "         _.' '._        " << endl;
    cout << "        '-------'       " << endl;
}

void writeWordToDB()
{
    string newWord;
    cout << "Write the new word, using Uppercase letters" << endl;
    cin >> newWord;

    vector<string> fileOfWords = readDB();
    fileOfWords.push_back(newWord);

    saveTheListOnTheDB(fileOfWords);
}

void wrongGuess()
{
    cout << "Wrong letters so far: ";

    for (char letter : guestWrong)
    {
        cout << letter << " ";
    }
    cout << endl;
}

bool failAllAtteempts()
{
    return guestWrong.size() < numberOfTries;
}

bool guessedTheWord()
{
    for (char letter : secretWord)
    {
        if (!guestAttempts[letter])
        {
            return true;
        }
    }

    return false;
}

bool wasTheLetter(char guess)
{
    bool haveTheLetter = false;

    for (char letter : secretWord)
    {
        if (letter == guess)
        {
            haveTheLetter = true;
        }
    }

    return haveTheLetter;
}

vector<string> readDB()
{
    // i - input, f - file, stream... to read files.
    ifstream file;
    file.open("words.txt");

    if (file.is_open())
    {

        int numberOfWords;
        file >> numberOfWords;

        vector<string> fileOfWords;

        for (int i = 0; i < numberOfWords; i++)
        {
            string readWord;
            file >> readWord;
            fileOfWords.push_back(readWord);
        }

        file.close();

        return fileOfWords;
    }
    else
    {
        cout << "Database is not accessible!" << endl;
        exit(0);
    }
}

int main()
{
    intro();
    chooseWord();

    while (failAllAtteempts() && guessedTheWord())
    {
        drawHangman();
        printTheWord();
        wrongGuess();

        char guess;
        cout << "What is your guest? ";
        cin >> guess;

        wasWrongGuess(guess);

        cout << endl;
    }

    cout << "The word was **" << secretWord << "**" << endl;
    endGame();
}