#include "Command.h"
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <iterator>
#include "WriteReadFile.h"

/*---------------CommandSequenceCreation----------------------*/

NewCmd::NewCmd(std::string sequence, std::string name) : m_name(name), m_sequence(sequence) {

}

std::string NewCmd::execute() {

    if (m_name == "empty") {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else {
        if (Data::checkSameName(m_name)) {
            return "enter another name\n";
        }
    }
    std::ostringstream line;
    std::ostringstream ss;
    ss << ++s_id;
    boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
    Data::s_sequence[ss.str()] = dna;
    Data::s_sequence[m_name] = dna;
    line << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";

    return line.str();
}


std::string PrintCmd::execute() {
    std::vector<std::string> keys;
    keys = Data::getAllKeysForValue(Data::s_sequence, Data::s_sequence.find(m_key)->second);
    std::cout << "[" << keys[0] << "] " << keys[1] << ": "
              << Data::s_sequence.find(m_key)->second->getsequence() << std::endl;

}


Load::Load(std::string path, std::string name) : m_path(path), m_name(name) {

}

std::string Load::execute() {
    if (m_name == "empty") {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else {
        if (Data::checkSameName(m_name)) {
            return "enter another name\n";
        }
    }
    std::string sequence;
    std::ostringstream line;
    ReadFile read(m_path);
    sequence = read.readfile();

    std::ostringstream ss;
    ss << ++s_id;
    boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(sequence));
    Data::s_sequence[ss.str()] = dna;
    Data::s_sequence[m_name] = dna;
    line << '[' << s_id << ']' << " " << m_name << ": " << sequence << "\n";

    return line.str();
}


Save::Save(std::string name, std::string pathw) : m_pathw(pathw), m_name(name) {

}

std::string Save::execute() {
    std::string m_sequence;
    m_sequence = Data::s_sequence.find(m_name)->second->getsequence();
    WriteFile write(m_pathw, m_sequence);
    write.writefile();
}
