#include "WriteReadFile.h"
#include <string.h>
#include <fstream>

void WriteReadFile::readfile() {
    std::string line;
    std::ifstream myfile1(m_path_read);
    while (getline(myfile1, line)) {
        m_dna_sequence.push_back(new DnaSequence(line.c_str()));
    }
    myfile1.close();
}

void WriteReadFile::writefile() {
    std::ofstream myfile(m_path_write);
    if (myfile.is_open()) {
        for (std::vector<DnaSequence *>::iterator it = m_dna_sequence.begin(); it != m_dna_sequence.end(); ++it) {
            myfile << (*it)->getsequence() << std::endl;
        }
        myfile.close();
    }
}

WriteReadFile::WriteReadFile(char *pathR, char *pathW, std::vector<DnaSequence *> dnaSequence) {
    m_path_read = pathR;
    m_path_write = pathW;
    m_dna_sequence = dnaSequence;
}

