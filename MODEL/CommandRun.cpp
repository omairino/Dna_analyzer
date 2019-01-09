#include "CommandRun.h"

void CommandRun::start() {
    s_commad["new"] = boost::shared_ptr<Command>(new NewCmd());
    s_commad["load"] = boost::shared_ptr<Command>(new Load());
    s_commad["save"] = boost::shared_ptr<Command>(new Save());
    s_commad["print"] = boost::shared_ptr<Command>(new PrintCmd());
    s_commad["list"] = boost::shared_ptr<Command>(new List());
    s_commad["pair"] = boost::shared_ptr<Command>(new Pair());
    s_commad["slice"] = boost::shared_ptr<Command>(new Slice());
}

