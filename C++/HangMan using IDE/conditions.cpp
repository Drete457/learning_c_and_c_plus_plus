#include "conditions.hpp"

namespace CONDITIONS {
    bool failAllAtteempts(const int size, const int& numberOfTries)
    {
        return size < numberOfTries;
    }

    bool guessedTheWord(const std::string& secretWord, const std::map<char, bool>& guestAttempts)
    {
        for (char letter : secretWord)
        {
            if (guestAttempts.find(letter) == guestAttempts.end() || !guestAttempts.at(letter))
            {
                return true;
            }
        }

        return false;
    }

    bool wasTheLetter(const char guess, const std::string& secretWord)
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
}