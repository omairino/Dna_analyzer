#include "Controller.h"
#include "../MODEL/CommandParser.h"

Controller::Controller(const CLI &cli, std::tr1::shared_ptr<Command> command) {
    m_cli = cli;
    m_command = command;
}

void Controller::split(std::string strToSplit) {
    std::vector<std::string> splittedStrings;
    CommandParser::parser(strToSplit, &splittedStrings);
    std::string line;

    if (splittedStrings[0] == "new")
        if (splittedStrings.size() > 1)
            if (splittedStrings.size() > 2) {
                m_command = std::tr1::shared_ptr<Command>(new NewCmd(splittedStrings[1], splittedStrings[2]));
                line = m_command->execute();
                print(line);
            } else {
                m_command = std::tr1::shared_ptr<Command> (new NewCmd(splittedStrings[1], "empty"));
                line = m_command->execute();
                print(line);
            }

    if (splittedStrings[0] == "print") {
        m_command = std::tr1::shared_ptr<Command> (new PrintCmd());
        m_command->execute();
    }

    if (splittedStrings[0] != "exit") {
        start();
    }
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
    std::tr1::shared_ptr<Command> command;
    CLI cli;
//    Command *command;
    Controller controller(cli, command);
    controller.start();
    return 0;
}