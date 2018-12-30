#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMANDRUN_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMANDRUN_H
#include "Command.h"

class CommandRun {
public:
    std::map<std::string,boost::shared_ptr<Command> > s_commad;
    void start();
};

#endif