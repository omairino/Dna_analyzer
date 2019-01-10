#include "Command.h"
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <iterator>
#include "WriteReadFile.h"

/*---------------CommandSequenceCreation----------------------*/


std::string NewCmd::execute(std::vector<std::string> data) {
    if (data.size() < 2) {
        return "enter sequence\n";
    }
    parsing(data);

    if (Data::checkSameName(m_name)) {
        return "enter another name\n";
    }
    if (m_name != "") {
        std::ostringstream line;
        std::ostringstream ss;
        ss << ++s_id;
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[ss.str()] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = 'o';
        line << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";
        return line.str();
    }
    return "enter name!!\n";
}

void NewCmd::parsing(std::vector<std::string> &data) {
    if (data.size() == 2) {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else {
        if (data.size() == 3 && data[2][0] == '@') {
            m_name = data[2];
            m_name.erase(0, 1);
        }
    }
    m_sequence = data[1];
}


std::string Load::execute(std::vector<std::string> data) {

    if (data.size() < 2) {
        return "enter the path\n";
    }

    parsing(data);

    if (Data::checkSameName(m_name)) {
        return "enter another name\n";
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
        Data::s_status[dna] = '-';
        line << '[' << s_id << ']' << " " << m_name << ": " << sequence << "\n";
        return line.str();
    }
    return "file is empty or not exists\n";
}

void Load::parsing(std::vector<std::string> &data) {
    if (data.size() == 2) {
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else if (data.size() == 3 && data[2][0] == '@') {

        m_name = data[2];
        m_name.erase(0, 1);
    }
    m_path = data[1];
}

std::string Dup::execute(std::vector<std::string> data) {
    if (data.size() < 2) {
        return "enter id or name\n";
    }
    parsing(data);
    if (Data::checkSameName(m_name)) {
        return "enter another name\n";
    }
    if (m_sequence != "") {
        std::ostringstream line;
        std::ostringstream ss;
        ss << ++s_id;
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[ss.str()] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = 'o';
        line << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";

        return line.str();
    }
    return "sequence is empty\n";
}

void Dup::parsing(std::vector<std::string> &data) {
    std::string key;
    std::string name;
    if (data.size() == 2) {
        if (data[1][0] == '#') {
            key = data[1];
            key.erase(0, 1);
            m_sequence = Data::s_sequencekey.find(key)->second->getsequence();
            m_sequence += m_sequence;
        } else {
            if (data[1][0] == '@') {
                name = data[1];
                name.erase(0, 1);

                if (Data::checkSameName(name)) {
                    m_sequence = Data::s_sequencename.find(name)->second->getsequence();
                    m_sequence += m_sequence;
                }
            }
        }
        std::ostringstream ss;
        ss << "seq" << (++s_name);
        m_name = ss.str();
    } else if (data.size() == 3 && data[2][0] == '@') {
        m_name = data[2];
        m_name.erase(0, 1);
    }
}


/*--------------------------------------end  CommandSequenceCreation------------------------*/






/*------------------------------------- Sequence Manipulation--------------------------------*/
size_t Pair::m_id = 0;

std::string Pair::execute(std::vector<std::string> data) {

    if (data.size() < 2)
        return "id or name is invalid\n";

    parsing(data);

    if (m_sequence.length() == 0) {
        return "id or name is invalid\n";
    }


    for (int i = 0; i < m_sequence.length(); i++) {
        if (m_sequence[i] == 'A')
            m_sequence[i] = 'T';
        else if (m_sequence[i] == 'T')
            m_sequence[i] = 'A';
        else if (m_sequence[i] == 'C')
            m_sequence[i] = 'G';
        else if (m_sequence[i] == 'G')
            m_sequence[i] = 'C';
    }

    std::ostringstream lins;
    if (data.size() == 2) {
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[m_key] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = '*';
        lins << '[' << m_key << ']' << " " << m_name << ": " << m_sequence << "\n";

    } else if (data.size() == 4) {

        if (Data::checkSameName(m_name)) {

            return "enter another name\n";

        }
        std::ostringstream ss;
        ss << ++s_id;
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[ss.str()] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = '*';
        lins << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";
    }
    m_name = "";
    m_sequence = "";
    m_key = "";
    return lins.str();
}

void Pair::parsing(std::vector<std::string> &data) {
    if (data.size() >= 2) {
        if (data[1][0] == '#') {
            std::string k = data[1];
            k.erase(0, 1);
            m_name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(k)->second);
            m_sequence = Data::s_sequencekey.find(k)->second->getsequence();
            m_key = k;
        } else if (data[1][0] == '@') {
            std::string name = data[1].erase(0, 1);
            m_sequence = Data::s_sequencename.find(name)->second->getsequence();
            m_name = name;
            m_key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencename.find(m_name)->second);
        }
    }

    std::ostringstream line;
    if (data.size() == 4) {
        if (data[3] == "@@") {
            line << m_name << "_p" << ++Pair::m_id;
            m_name = line.str();
        } else if (data[3][0] == '@') {
            m_name = data[3];
            m_name.erase(0, 1);
        }
    }
}


size_t Slice::m_id = 0;

std::string Slice::execute(std::vector<std::string> data) {

    if (data.size() < 4)
        return "id or name or index invalid\n";
    parsing(data);
    if (m_sequence.length() == 0) {
        return "id or name is invalid\n";
    }

    std::ostringstream ss;
    std::ostringstream lins;
    size_t from = 0, to = 0;
    std::istringstream(data[2]) >> from;
    std::istringstream(data[3]) >> to;
    m_sequence = m_sequence.substr(from, to - 1);


    if (data.size() == 4) {
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[m_key] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = '*';
        lins << '[' << m_key << ']' << " " << m_name << ": " << m_sequence << "\n";

    } else if (data.size() == 6) {

        if (Data::checkSameName(m_name)) {

            return "enter another name\n";

        }

        ss << ++s_id;
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[ss.str()] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = '*';
        lins << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";
    }
    m_name = "";
    m_key = "";
    m_sequence = "";
    return lins.str();

}

void Slice::parsing(std::vector<std::string> &data) {

    if (data.size() > 3) {
        if (data[1][0] == '#') {
            std::string k = data[1];
            k.erase(0, 1);
            m_name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(k)->second);
            m_sequence = Data::s_sequencekey.find(k)->second->getsequence();
            m_key = k;
        } else {
            if (data[1][0] == '@') {
                m_name = data[1].erase(0, 1);
                m_sequence = Data::s_sequencename.find(m_name)->second->getsequence();
                m_key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencename.find(m_name)->second);
            }
        }
    }

    std::ostringstream line;
    if (data.size() == 6) {
        if (data[5] == "@@") {
            line << m_name << "_s" << ++Slice::m_id;
            m_name = line.str();
        } else if (data[5][0] == '@') {
            m_name = data[5];
            m_name.erase(0, 1);
        }

    }

}

size_t Replace::m_id = 0;

std::string Replace::execute(std::vector<std::string> data) {
    if (data.size() < 4) {
        return "id or name or seq invalid";
    }
    int size = parsing(data);

    int index;
    char character;
    for (int i = 0; i < size; i += 2) {
        std::istringstream(data[i + 2]) >> index;
        character = (data[i + 3])[0];
        m_sequence[index] = character;
    }

    if (m_sequence.length() == 0) {
        return "error sequence\n";
    }

    if (Data::checkSameName(m_name)) {
        std::ostringstream lins;
        std::string m_key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencename.find(m_name)->second);
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[m_key] = dna;
        Data::s_sequencename[m_name] = dna;
        Data::s_status[dna] = '*';
        lins << '[' << m_key << ']' << " " << m_name << ": " << m_sequence << "\n";
        return lins.str();
    }

    std::ostringstream ss;
    std::ostringstream lins;
    ss << ++s_id;
    boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
    Data::s_sequencekey[ss.str()] = dna;
    Data::s_sequencename[m_name] = dna;
    Data::s_status[dna] = '*';
    lins << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";
    return lins.str();

}

int Replace::parsing(std::vector<std::string> &data) {
    if (data[1][0] == '#') {
         m_key = data[1];
        m_key.erase(0, 1);
        m_name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(m_key)->second);
        m_sequence = Data::s_sequencekey.find(m_key)->second->getsequence();
    } else {
        if (data[1][0] == '@') {
            m_name = data[1].erase(0, 1);
            m_sequence = Data::s_sequencename.find(m_name)->second->getsequence();
        }
    }

    int size = 0;
    if (data.size() > 6) {

        if (data[data.size() - 1] == "@@") {
            std::ostringstream line;
            line << m_name << "_r" << ++Replace::m_id;
            m_name = line.str();
        } else {
            m_name = data[data.size() - 1];
            m_name.erase(0, 1);
        }
        size = (int) (data.size() - 4);
    } else {
        size = (int) (data.size() - 2);
    }
    return size;
}

size_t Concat::m_id = 0;

std::string Concat::execute(std::vector<std::string> data) {
    int size = 0;
    if (data[1][0] == '#') {
        std::string key = data[1];
        key.erase(0, 1);
        m_name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(key)->second);
        m_sequence = Data::s_sequencekey.find(key)->second->getsequence();
    } else {
        m_name = data[1];
        m_sequence = Data::s_sequencename.find(m_name)->second->getsequence();
    }

    if (data.size() > 3) {

        if (data[data.size() - 1] == "@@") {
            std::ostringstream line;
            line << m_name << "_r" << ++Replace::m_id;
            m_name = line.str();
        } else {
            m_name = data[data.size() - 1];
            m_name.erase(0, 1);
        }
        size = (int) (data.size() - 3);
    } else {
        size = (int) (data.size() - 1);
    }
    std::string indexkey;
    if ((data[1][0] != '#')) {
        for (int i = 1; i < size; i++) {
            m_sequence += Data::s_sequencename.find(data[i + 1])->second->getsequence();
        }
    } else {
        for (int i = 1; i < size; i++) {
            indexkey = data[i + 1];
            indexkey.erase(0, 1);
            m_sequence += Data::s_sequencekey.find(indexkey)->second->getsequence();
        }
    }


    if (m_sequence.length() == 0) {
        return "error\n";
    }
    if (Data::checkSameName(m_name)) {
        std::ostringstream lins;
        std::string key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencename.find(m_name)->second);
        boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
        Data::s_sequencekey[key] = dna;
        Data::s_sequencename[m_name] = dna;
        lins << '[' << key << ']' << " " << m_name << ": " << m_sequence << "\n";
        return lins.str();
    }

    std::ostringstream ss;
    std::ostringstream lins;
    ss << ++s_id;
    boost::shared_ptr<DnaSequence> dna = boost::shared_ptr<DnaSequence>(new DnaSequence(m_sequence));
    Data::s_sequencekey[ss.str()] = dna;
    Data::s_sequencename[m_name] = dna;
    lins << '[' << s_id << ']' << " " << m_name << ": " << m_sequence << "\n";
    return lins.str();
}

/*------------------------------------- End Sequence Manipulation!!--------------------------------*/


std::string Save::execute(std::vector<std::string> data) {
    std::string m_sequence;

    if (data.size() == 3) {
        m_name = data[2];
        m_pathw = data[1];
    } else if (data.size() == 2) {
        m_name = data[1];
        m_pathw = data[1];
    }
    if (Data::s_sequencename.find(m_name) == Data::s_sequencename.end()) {
        return "name not exists\n";
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
        line << "[" << it->first << "] " << st << ": " << it->second->getsequence() << '\n';
        it++;
    }
    return line.str();
}


/*-------------------------------------------Sequence Management--------------------------------*/

std::string Rename::execute(std::vector<std::string> data) {
    std::string key;
    std::string newName;
    boost::shared_ptr<DnaSequence> dna;
    if (data.size() == 3) {
        if (data[1][0] == '#') {
            std::string k = data[1];
            k.erase(0, 1);
            m_name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(k)->second);
            dna = Data::s_sequencekey.find(k)->second;
        } else {
            dna = Data::s_sequencename.find(data[1])->second;
            m_name = data[1];
        }

        if (data[2][0] == '@') {
            newName = data[2];
            newName.erase(0, 1);

            if (Data::checkSameName(newName)) {
                return "enter another name\n";
            }
            Data::s_sequencename[newName] = dna;
            Data::s_sequencename.erase(m_name);
            return "success\n";
        }
        return "invalid\n";
    }
    return "invalid\n";
}

/*----------------------------------------End Sequence Management!!--------------------------------*/


std::string Delete::execute(std::vector<std::string> data) {
    std::string key, name;
    if (data.size() == 2) {
        if (data[1][0] == '#') {
            key = data[1];
            key.erase(0, 1);
            name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(key)->second);

        } else if (Data::checkSameName(data[1])) {
            name = data[1];
            key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencename.find(name)->second);
        } else {
            return "invalid";
        }
        Data::s_sequencename.erase(name);
        Data::s_sequencekey.erase(key);
        return "success";
    }
    return "invalid";
}


std::string Len::execute(std::vector<std::string> data) {
    if (Data::s_sequencekey.find(data[1]) != Data::s_sequencekey.end()) {
        std::ostringstream length;
        length << Data::s_sequencekey.find(data[1])->second->getsequence().length() << std::endl;
        return length.str();
    }
    return "id invalid\n";
}

/*-----------------------------------add more comand--------------------*/
std::string PrintCmd::execute(std::vector<std::string> data) {
    std::ostringstream ss;
    std::string key, name;
    if (data.size() == 2) {
        m_key = data[1];
        if (data[1][0] == '#') {
            m_key.erase(0, 1);
            key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencekey.find(m_key)->second);
            name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencekey.find(m_key)->second);
            ss << "[" << key << "] " << name << ": "
               << Data::s_sequencekey.find(key)->second->getsequence() << std::endl;
        } else {
            name = Data::getAllKeysForValue(Data::s_sequencename, Data::s_sequencename.find(m_key)->second);
            key = Data::getAllKeysForValue(Data::s_sequencekey, Data::s_sequencename.find(m_key)->second);
            ss << "[" << key << "] " << name << ": "
               << Data::s_sequencekey.find(key)->second->getsequence() << std::endl;
        }

    }
    return ss.str();

}


