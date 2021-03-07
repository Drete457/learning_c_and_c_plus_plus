#pragma once

#include <map>
#include <string>

namespace CONDITIONS {
    bool failAllAtteempts(const int size, const int& numberOfTries);
    bool guessedTheWord(const std::string& secretWord, const std::map<char, bool>& guestAttempts);
    bool wasTheLetter(const char guess, const std::string& secretWord);
}
