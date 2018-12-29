#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H

#include <iostream>
#include <vector>
#include <sstream>
#include "../VIEW/Cmd.h"
#include "../MODEL/Command.h"
#include <tr1/memory>

class Controller {
public:
    Controller();

    Controller(const CLI &cli, Command *command);

    void start();

    void split(std::string strToSplit, char delimeter);

    void print(std::string line);


private:
    CLI m_cli;
    Command *m_command;
};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H
