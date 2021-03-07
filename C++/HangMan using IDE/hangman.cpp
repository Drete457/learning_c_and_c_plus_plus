#include "hangman.hpp"

static const std::string secretWord = READ::chooseWord();
static const int numberOfTries = 6;

int main()
{
    std::map<char, bool> guestAttempts;
    std::vector<char> guestWrong;

    UI::intro(); 

    while (CONDITIONS::failAllAtteempts(guestWrong.size(), numberOfTries) && CONDITIONS::guessedTheWord(secretWord, guestAttempts))
    {
        UI::drawHangman(guestWrong.size(), numberOfTries);
        UI::printTheWord(secretWord, guestAttempts);
        UI::wrongGuess(guestWrong);

        char guess;
        std::cout << "What is your guest? ";
        std::cin >> guess;
       
        UI::wasWrongGuess(guess, secretWord, guestAttempts, guestWrong);

        std::cout << std::endl;
    }

    std::cout << "The word was **" << secretWord << "**" << std::endl;

    if (!CONDITIONS::failAllAtteempts(guestWrong.size(), numberOfTries))
    {         
        UI::gameOver();
    }
    else
    {
        UI::winner();
        WRITE::addWordToDB();    
    }     
}