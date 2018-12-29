#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CLI_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CLI_H

#include <iostream>
#include <vector>
#include <sstream>


class CLI {
public:
    CLI();

    std::string start();

    void print(std::string line);

private:
    std::string line;


};


#endif
