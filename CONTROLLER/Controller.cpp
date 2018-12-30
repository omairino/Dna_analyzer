#include "Controller.h"
#include "../MODEL/CommandParser.h"


Controller::Controller(const CLI &cli, CommandRun &command) {
    m_cli = cli;
    m_command = command;
}

void Controller::split(std::string strToSplit) {
    std::vector<std::string> splittedStrings;
    CommandParser::parser(strToSplit, &splittedStrings);
    std::string line;
    if (splittedStrings.size() > 0) {
        if (Data::s_sequence.find(splittedStrings[0]) != Data::s_sequence.end()) {
            if (splittedStrings[0] != "exit") {
                line = m_command.s_commad.find(splittedStrings[0])->second->execute(splittedStrings);
                print(line);
                start();
            }
        }}
        start();

}

Controller::Controller() {

}

void Controller::start() {
    split(m_cli.start());
}

void Controller::print(std::string line) {
    m_cli.print(line);
}


int main() {
    CLI cli;
    CommandRun run;
    run.start();
    Controller controller(cli, run);
    controller.start();
    return 0;
}