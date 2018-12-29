#include "Cmd.h"


std::string CLI::start() {
        std::cout << "cmd>";
        std::getline(std::cin, line);
        return line;
}


CLI::CLI() {
}

void CLI::print(std::string line) {
    std::cout<<line;
}
