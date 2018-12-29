#include "WriteReadFile.h"
#include <string.h>
#include <fstream>
#include <sstream>

ReadFile::ReadFile(std::string pathR) : m_path_read(pathR) {

}

std::string ReadFile::readfile() {
    std::string line;
    std::ifstream myfile1(m_path_read.c_str());
    getline(myfile1, line);
    myfile1.close();
    return line;
}


void WriteFile::writefile() {
    std::ostringstream ss;
    ss<<m_path_write<<".rawdna";
    FILE *file = fopen (const_cast<char*>((ss.str()).c_str()), "w+");
    int return_val = fputs (const_cast<char*>(m_sequence.c_str()), file);
    if (return_val >= 0)
        printf ("Success");
    else
        printf ("failed");

    fclose (file);
//    std::ofstream myfile((ss.str()).c_str());
//    if (myfile.is_open()) {
//        myfile << m_sequence;
//        std::cout<<ss.str();
//        myfile.close();
//    }
}

WriteFile::WriteFile(std::string pathW, std::string sequence) : m_path_write(pathW), m_sequence(sequence) {
}