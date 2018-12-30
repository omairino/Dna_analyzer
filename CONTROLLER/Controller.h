#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H

#include <iostream>
#include <vector>
#include <sstream>
#include "../VIEW/Cmd.h"
#include "../MODEL/Command.h"
#include <boost/shared_ptr.hpp>
#include "../MODEL/CommandRun.h"

class Controller {
public:
    Controller();

    Controller(const CLI &cli,CommandRun &command);

    void start();

    void split(std::string strToSplit);

    void print(std::string line);


private:
    CLI m_cli;
//    boost::shared_ptr<Command> m_command;
    CommandRun m_command;
};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_CONTROLLER_H
