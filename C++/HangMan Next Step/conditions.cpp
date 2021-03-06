#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "conditions.hpp"

extern std::string secretWord;
extern int numberOfTries;
extern std::map<char, bool> guestAttempts;
extern std::vector<char> guestWrong;

bool failAllAtteempts()
{
    return guestWrong.size() < unsigned(numberOfTries);
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