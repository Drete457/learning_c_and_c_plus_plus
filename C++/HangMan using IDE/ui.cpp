#include "ui.hpp"

namespace UI {
    void drawHangman(const int size, const int& numberOfTries)
    {
        int head = numberOfTries / numberOfTries;
        double body = numberOfTries * 0.30;
        double arms = numberOfTries * 0.60;
        double legs = numberOfTries * 0.80;

        int errors = size;

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

    void printTheWord(const std::string& secretWord, const std::map<char, bool>& guestAttempts)
    {
        for (char letter : secretWord)
        {
            bool letterWasChoose = !(guestAttempts.find(letter) == guestAttempts.end());

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

    void wasWrongGuess(const char guess, const std::string& secretWord, std::map<char, bool>& guestAttempts, std::vector<char>& guestWrong)
    {
        bool haveTheLetter = CONDITIONS::wasTheLetter(guess, secretWord);
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

    void wrongGuess(const std::vector<char>& guestWrong)
    {
        std::cout << "Wrong letters so far: ";

        for (char letter : guestWrong)
        {
            std::cout << letter << " ";
        }

        std::cout << std::endl;
    }
}