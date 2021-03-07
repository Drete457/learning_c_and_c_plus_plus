#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "conditions.hpp"

namespace UI {
    using namespace std;

    void drawHangman(const int size, const int& numberOfTries);
    void printTheWord(const string& secretWord, const map<char, bool>& guestAttempts);
    void wasWrongGuess(const char guess, const string& secretWord, map<char, bool>& guestAttempts, vector<char>& guestWrong);
    void wrongGuess(const vector<char>& guestWrong);

    inline void intro()
    {
        cout << "******************************************" << endl;
        cout << "*      Welcome to our Hangman game!      *" << endl;
        cout << "******************************************" << endl;
        cout << "   Note: Letters need to be in Uppercase  " << endl;
        cout << endl;
    }

    inline void gameOver()
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

    inline void winner()
    {
        cout << " Congratulation, you won! " << endl;
        cout << "       ___________        " << endl;
        cout << "      '._==_==_=_.'       " << endl;
        cout << "      .-\\:      /-.      " << endl;
        cout << "     | (|:.     |) |      " << endl;
        cout << "      '-|:.     |-'       " << endl;
        cout << "        \\::.    /        " << endl;
        cout << "         '::. .'          " << endl;
        cout << "           ) (            " << endl;
        cout << "         _.' '._          " << endl;
        cout << "        '-------'         " << endl;
    }
}