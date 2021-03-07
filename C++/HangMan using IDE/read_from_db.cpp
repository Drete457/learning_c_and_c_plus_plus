#include "read_from_db.hpp"

namespace READ {
    std::string chooseWord()
    {
        std::vector<std::string> fileOfWords = readDB();

        srand(unsigned(time(NULL)));
        int chooseWord = rand() % fileOfWords.size();

        return fileOfWords[chooseWord];
    }

    std::vector<std::string> readDB()
    {
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
}
