#include "Command.h"
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <iterator>
#include "WriteReadFile.h"

/*---------------CommandSequenceCreation----------------------*/

NewCmd::NewCmd(std::vector<std::string> data) : m_sequence(data[1]) {
    if (data.size() > 2)
        m_name = data[2];
    else
        m_name = "empty";

}

std::string NewCmd::execute(std::vector<std::string> data) {
    m_sequence = data[1];
    if (data.size() < 3) {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else {
        m_name = data[2];
        if (Data::checkSameName(data[2])) {
            return "enter another name\n";
        }
    }
    std::ostringstream line;
    std::ostringstream ss;
    ss << ++s_id;
    boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
    Data::s_sequencekey[ss.str()] = dna;
    Data::s_sequencename[m_name] = dna;
    line << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";

    return line.str();
}


std::string PrintCmd::execute(std::vector<std::string> data) {
    m_key = data[1];
    std::ostringstream ss;
    std::string key ,name;
    key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencekey.find(m_key)->second);
    name = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencekey.find(m_key)->second);
    ss << "[" << key << "] " << name << ": "
       << Data::s_sequencekey.find(key)->second->getsequence() << std::endl;
    return ss.str();

}


Load::Load(std::vector<std::string> data) : m_path(data[1]) {
    if (data.size() > 2)
        m_name = data[2];
    else
        m_name = "empty";

}

std::string Load::execute(std::vector<std::string> data) {
    m_path = data[1];
    if (data.size() < 3) {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else {
        m_name = data[2];
        if (Data::checkSameName(m_name)) {
            return "enter another name\n";
        }
    }
    std::string sequence;
    std::ostringstream line;

    ReadFile read(m_path);
    sequence = read.readfile();

    if (sequence != "") {
        std::ostringstream ss;
        ss << ++s_id;
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(sequence));
        Data::s_sequencekey[ss.str()] = dna;
        Data::s_sequencename[m_name] = dna;
        line << '[' << s_id << ']' << " " << m_name << ": " << sequence << "\n";
        return line.str();
    }
    return "file is empty or not exists\n";
}


Save::Save(std::vector<std::string> data) : m_pathw(data[1]) {
    if (data.size() > 2)
        m_name = data[2];
    else
        m_name = data[1];

}

std::string Save::execute(std::vector<std::string> data) {
    std::string m_sequence;
    m_pathw = data[1];
    if (data.size() > 2)
        m_name = data[2];
    else
        m_name = data[1];
    if (Data::s_sequencename.find(m_name) == Data::s_sequencename.end()) {
        return "id or name not exists\n";
    }
    m_sequence = Data::s_sequencename.find(m_name)->second->getsequence();
    WriteFile write(m_pathw, m_sequence);
    write.writefile();
    return "save success!!\n";
}

std::string List::execute(std::vector<std::string> data) {
    std::map<std::string, boost::shared_ptr<DnaSequence> >::iterator it = Data::s_sequencekey.begin();
    std::ostringstream line;
    std::string st;
    while (it != Data::s_sequencekey.end()) {
        st = Data::getAllKeysForValue(Data::s_sequencename, it->second);
        line << "[" << it->first << "] " << st  << ": " << it->second->getsequence() << '\n';
        it++;
    }
    return line.str();
}
