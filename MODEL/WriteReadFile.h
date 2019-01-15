#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_WRITEREADFILE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_WRITEREADFILE_H

#include "DnaSequence.h"


class ReadFile {
public:
    ReadFile(std::string pathR);

    std::string readfile();


private:
    std::string m_path_read;


};

class WriteFile {
public:
    WriteFile(std::string pathW, boost::shared_ptr<IDna> sequence);

    void writefile();

private:
    std::string m_path_write;
    boost::shared_ptr<IDna> m_sequence;


};

#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_WRITEREADFILE_H
