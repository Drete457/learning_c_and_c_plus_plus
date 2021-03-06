#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>

#include "read_from_db.hpp"

extern std::string secretWord;

void chooseWord()
{
    std::vector<std::string> fileOfWords = readDB();

    srand(unsigned(time(NULL)));
    const int chooseWord = rand() % fileOfWords.size();

    secretWord = fileOfWords[chooseWord];
}

std::vector<std::string> readDB()
{
    // i - input, f - file, stream... to read files.
    std::ifstream file;
    file.open("words.txt");

    if (file.is_open())
    {

        int numberOfWords;
        file >> numberOfWords;

        std::vector<std::string> fileOfWords;

        for (int i = 0; i < numberOfWords; i++)
        {
            std::string readWord;
            file >> readWord;
            fileOfWords.push_back(readWord);
        }

        file.close();

        return fileOfWords;
    }
    else
    {
        std::cout << "Database is not accessible!" << std::endl;
        exit(0);
    }
}
