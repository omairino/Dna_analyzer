#include "CommandParser.h"
#include <sstream>

void CommandParser::parser(std::string line, std::vector<std::string> *splittedStrings) {
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        splittedStrings->push_back(token);
    }

}

