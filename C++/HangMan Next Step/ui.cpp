#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "conditions.hpp"
#include "ui.hpp"
#include "write_to_db.hpp"

extern std::string secretWord;
extern int numberOfTries;
extern std::map<char, bool> guestAttempts;
extern std::vector<char> guestWrong;

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
    std::cout << "******************************************" << std::endl;
    std::cout << "*      Welcome to our Hangman game!      *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "   Note: Letters need to be in Uppercase  " << std::endl;
    std::cout << std::endl;
}

void gameOver()
{
    std::cout << "Gosh, you were hanged!" << std::endl;

    std::cout << "    _______________         " << std::endl;
    std::cout << "   /               \\       " << std::endl;
    std::cout << "  /                 \\      " << std::endl;
    std::cout << "//                   \\/\\  " << std::endl;
    std::cout << "\\|   XXXX     XXXX   | /   " << std::endl;
    std::cout << " |   XXXX     XXXX   |/     " << std::endl;
    std::cout << " |   XXX       XXX   |      " << std::endl;
    std::cout << " |                   |      " << std::endl;
    std::cout << " \\__      XXX      __/     " << std::endl;
    std::cout << "   |\\     XXX     /|       " << std::endl;
    std::cout << "   | |           | |        " << std::endl;
    std::cout << "   | I I I I I I I |        " << std::endl;
    std::cout << "   |  I I I I I I  |        " << std::endl;
    std::cout << "   \\_             _/       " << std::endl;
    std::cout << "     \\_         _/         " << std::endl;
    std::cout << "       \\_______/           " << std::endl;
}

void drawHangman()
{
    double head = numberOfTries / numberOfTries;
    double body = numberOfTries * 0.30;
    double arms = numberOfTries * 0.60;
    double legs = numberOfTries * 0.90;

    int errors = guestWrong.size();

    std::cout << "  _______       " << std::endl;
    std::cout << " |/      |      " << std::endl;
    std::cout << " |      " << (errors >= head ? '(' : ' ') << (errors >= head ? '_' : ' ') << (errors >= head ? ')' : ' ') << std::endl;
    std::cout << " |      " << (errors >= arms ? '\\' : ' ') << (errors >= body ? '|' : ' ') << (errors >= arms ? '/' : ' ') << std::endl;
    std::cout << " |       " << (errors >= body ? '|' : ' ') << std::endl;
    std::cout << " |      " << (errors >= legs ? '/' : ' ') << (errors >= legs ? (char)39 : ' ') << (errors >= legs ? '\\' : ' ') << std::endl;
    std::cout << " |              " << std::endl;
    std::cout << "_|___           " << std::endl;
    std::cout << std::endl;
}

void printTheWord()
{
    //we can user the proprity size() to know the size of the word for the for or use this for to make the same thing. ex: for (int i = 0; i < SECRET_WORD.size() ; i++){}
    for (char letter : secretWord)
    {
        bool letterWasChoose = guestAttempts[letter];

        if (letterWasChoose)
        {
            std::cout << letter << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }

    std::cout << std::endl;
}

void wasWrongGuess(char guess)
{
    bool haveTheLetter = wasTheLetter(guess);
    guestAttempts[guess] = true;

    if (haveTheLetter)
    {
        std::cout << "Your guess was correct" << std::endl;
    }
    else
    {
        std::cout << "Your guess was incorrect" << std::endl;
        guestWrong.push_back(guess);
    }

    std::cout << std::endl;
}

void winner()
{
    std::cout << " Congratulation, you won! " << std::endl;

    std::cout << "       ___________      " << std::endl;
    std::cout << "      '._==_==_=_.'     " << std::endl;
    std::cout << "      .-\\:      /-.    " << std::endl;
    std::cout << "     | (|:.     |) |    " << std::endl;
    std::cout << "      '-|:.     |-'     " << std::endl;
    std::cout << "        \\::.    /      " << std::endl;
    std::cout << "         '::. .'        " << std::endl;
    std::cout << "           ) (          " << std::endl;
    std::cout << "         _.' '._        " << std::endl;
    std::cout << "        '-------'       " << std::endl;
}

void wrongGuess()
{
    std::cout << "Wrong letters so far: ";

    for (char letter : guestWrong)
    {
        std::cout << letter << " ";
    }

    std::cout << std::endl;
}