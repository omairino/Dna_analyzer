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

    Controller(const CLI &cli, std::tr1::shared_ptr<Command> command);

    void start();

    void split(std::string strToSplit);

    void print(std::string line);


private:
    CLI m_cli;
    std::tr1::shared_ptr<Command> m_command;
};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H
