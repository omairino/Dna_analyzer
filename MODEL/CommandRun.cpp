#include "CommandRun.h"

void CommandRun::start() {
    s_commad["new"] = boost::shared_ptr<Command>(new NewCmd());
    s_commad["load"] = boost::shared_ptr<Command>(new Load());
    s_commad["save"] = boost::shared_ptr<Command>(new Save());
    s_commad["print"] = boost::shared_ptr<Command>(new PrintCmd());
}

