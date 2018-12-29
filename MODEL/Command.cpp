#include "Command.h"
#include <sstream>

/*---------------CommandSequenceCreation----------------------*/

NewCmd::NewCmd(std::string sequence, std::string name) : m_name(name) {
    m_sequence = sequence;
}

std::string NewCmd::execute() {
    DNA newseq;
    std::ostringstream line;
    newseq.id = ++ids;
    newseq.name = m_name;
    newseq.sequence = m_sequence;
    Data::s_sequences.push_back(newseq);
    line << '[' << newseq.id << ']' << " " << m_sequence << " " << newseq.name << "\n";
    return line.str();
}


std::string PrintCmd::execute() {
    for (int i = 0; i < Data::s_sequences.size(); i++) {
        std::cout << "[" << Data::s_sequences[i].id << "] " << Data::s_sequences[i].sequence << " "
                  << Data::s_sequences[i].name << std::endl;
    }
    return "";
}
