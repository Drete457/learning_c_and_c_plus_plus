#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "read_from_db.hpp"

namespace WRITE {
    void addWordToDB();
    void saveTheListOnTheDB(const std::vector<std::string>& fileOfWords);
    void writeWordToDB();
}
