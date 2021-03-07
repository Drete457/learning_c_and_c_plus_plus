#include "write_to_db.hpp"

namespace WRITE {
    void addWordToDB()
    {
        char answer;
        std::cout << "Do you want to add a new word in the game? (Y/N)" << std::endl;
        std::cin >> answer;

        if (answer == 'Y')
        {
            writeWordToDB();
        }
    }

    void saveTheListOnTheDB(const std::vector<std::string>& newList)
    {
        std::ofstream file;
        file.open("words.txt");

        if (file.is_open())
        {
            file << newList.size() << std::endl;

            for (std::string word : newList)
            {
                file << word << std::endl;
            }

            file.close();

            std::cout << "Word Successfully Added" << std::endl;
        }
        else
        {
            std::cout << "Database is not accessible!" << std::endl;
        }
    }

    void writeWordToDB()
    {
        std::string newWord;
        std::cout << "Write the new word, using Uppercase letters" << std::endl;
        std::cin >> newWord;

        std::vector<std::string> fileOfWords = READ::readDB();
        fileOfWords.push_back(newWord);

        saveTheListOnTheDB(fileOfWords);
    }
}