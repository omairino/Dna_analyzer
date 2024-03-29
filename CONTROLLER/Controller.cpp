#include "Controller.h"
#include "../MODEL/CommandParser.h"


Controller::Controller(const CLI &cli, CommandRun &command) {
    m_cli = cli;
    m_command = command;
}

void Controller::run(std::string strToSplit) {
    std::vector<std::string> splittedStrings;
    CommandParser::parser(strToSplit, &splittedStrings);
    std::string line;
    if (splittedStrings.size() > 0) {
        if (m_command.s_commad.find(splittedStrings[0]) != m_command.s_commad.end()) {
            line = m_command.s_commad.find(splittedStrings[0])->second->execute(splittedStrings);
            m_cli.print(line);
        }
        if (splittedStrings[0] == "exit") {
            exit(0);
        }
    }
    start();
}

Controller::Controller() {

}

void Controller::start() {
    run(m_cli.start());
}



int main() {
    CLI cli;
    CommandRun run;
    run.start();
    Controller controller(cli, run);
    controller.start();
    return 0;
}