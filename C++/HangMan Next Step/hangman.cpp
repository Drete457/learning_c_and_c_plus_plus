#include <iostream>
//have the ifstream type
#include <fstream>
//have the map type
#include <map>
//have the string type
#include <string>
//have the vector type
#include <vector>

#include "conditions.hpp"
#include "hangman.hpp"
#include "read_from_db.hpp"
#include "ui.hpp"
#include "write_to_db.hpp"

std::string secretWord;
int numberOfTries = 6;
//creates a map that receives some format and returns another format
std::map<char, bool> guestAttempts;
std::vector<char> guestWrong;

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
        std::cout << "What is your guest? ";
        std::cin >> guess;

        wasWrongGuess(guess);

        std::cout << std::endl;
    }

    std::cout << "The word was **" << secretWord << "**" << std::endl;
    endGame();
}