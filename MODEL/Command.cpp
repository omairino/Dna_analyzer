#include "Command.h"
#include <sstream>
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
        if (checkSameName()) {
            return "enter another name\n";
        }
    }
    DNA newseq;
    std::ostringstream line;
    DnaSequence dna(m_sequence);
    newseq.id = ++s_id;
    newseq.name = m_name;
    newseq.sequence = dna;
    Data::s_sequences.push_back(newseq);
    line << '[' << newseq.id << ']' << " " << newseq.name << ": " << m_sequence << "\n";

    return line.str();
}

bool NewCmd::checkSameName() {
    for (int i = 0; i < Data::s_sequences.size(); i++) {
        if (Data::s_sequences[i].name == m_name)
            return true;
    }
    return false;
}


std::string PrintCmd::execute() {
    for (int i = 0; i < Data::s_sequences.size(); i++) {
        std::cout << "[" << Data::s_sequences[i].id << "] " << Data::s_sequences[i].sequence << " "
                  << Data::s_sequences[i].name << std::endl;
    }
    return "";
}

Load::Load(std::string path, std::string name) : m_path(path), m_name(name) {

}

std::string Load::execute() {
    if (m_name == "empty") {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else {
        if (checkSameName()) {
            return "enter another name\n";
        }
    }
    std::string sequence;
    std::ostringstream line;
    ReadFile read(m_path);
    sequence = read.readfile();
    DnaSequence dna(sequence);
    DNA data;
    data.id = ++s_id;
    data.name = m_name;
    data.sequence = dna;
    Data::s_sequences.push_back(data);

    line << '[' << data.id << ']' << " " << data.name << ": " << sequence << "\n";
    return line.str();
}

bool Load::checkSameName() {

    for (int i = 0; i < Data::s_sequences.size(); i++) {
        if (Data::s_sequences[i].name == m_name)
            return true;
    }
    return false;

}



Save::Save(std::string name,std::string pathw ):m_pathw(pathw) ,m_name(name){

}

std::string Save::execute() {
    std::string m_sequence;
    for(int i=0;i<Data::s_sequences.size();i++){
        if(Data::s_sequences[i].name == m_name){
            m_sequence = Data::s_sequences[i].sequence.getsequence();
            break;
        }
    }
    WriteFile write(m_pathw,m_sequence);
    write.writefile();
}
