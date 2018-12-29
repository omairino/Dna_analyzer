#include "Controller.h"

Controller::Controller(const CLI &cli, Command *command) {
    m_cli = cli;
    m_command = command;
}

void Controller::split(std::string strToSplit, char delimeter) {
    std::stringstream ss(strToSplit);
    std::string item;
    std::string line;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }

    if (splittedStrings[0] == "new")
        if (splittedStrings.size() > 1)
            if (splittedStrings.size() > 2) {
                m_command = new NewCmd(splittedStrings[1], splittedStrings[2]);
                line = m_command->execute();
                print(line);
            }

    if (splittedStrings[0] == "print") {
        m_command = new PrintCmd();
        m_command->execute();
    }

    if (splittedStrings[0] != "exit") {
        start();
    }
}

Controller::Controller() {

}

void Controller::start() {
    split(m_cli.start(), ' ');
}

void Controller::print(std::string line) {
    m_cli.print(line);
}


int main() {

    CLI cli;
    Command *command;
    Controller controller(cli, command);
    controller.start();
//    std::string ss="GAA";
//    DnaSequence s1 = DnaSequence("AAA");
//    DnaSequence s2 = DnaSequence("GGGGG");
//    DnaSequence s3 = DnaSequence("AAA");
//    DnaSequence s4;
//    s2 = "AAAA";
//    s1 = ss;
//    s3= ss;
//    s4 = ss;
//    s1 = "GGGGG";
//    s4 = "GGG";
//
//    std::cout<<s1<<std::endl;
//    std::cout<<s2<<std::endl;
//    std::cout<<s3<<std::endl;
//    std::cout<<s4<<std::endl;
    return 0;
}