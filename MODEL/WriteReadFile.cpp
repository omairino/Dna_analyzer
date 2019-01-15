#include "WriteReadFile.h"
#include <string.h>
#include <fstream>
#include <sstream>

ReadFile::ReadFile(std::string pathR) : m_path_read(pathR) {

}

std::string ReadFile::readfile() {
    std::string line;
    std::ostringstream ss;
    ss<<"../DATASEQUENCE/"<<m_path_read;
    std::ifstream myfile1((ss.str()).c_str());
    getline(myfile1, line);
    myfile1.close();
    return line;
}


void WriteFile::writefile() {
    std::ostringstream ss;
    ss<<"../DATASEQUENCE/"<<m_path_write<<".rawdna";
    std::ofstream myfile((ss.str()).c_str(),std::ios::out);
    if (myfile.is_open()) {
        for(int i=0;i<m_sequence->size();i++)
        myfile << m_sequence->operator[](i);
        myfile.close();
    }
}

WriteFile::WriteFile(std::string pathW, boost::shared_ptr<IDna> sequence) : m_path_write(pathW), m_sequence(sequence) {
}