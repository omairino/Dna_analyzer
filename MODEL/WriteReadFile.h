#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_WRITEREADFILE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_WRITEREADFILE_H

#include "DnaSequence.h"
#include <vector>

class WriteReadFile {

public:
    WriteReadFile(char *pathR, char *pathW, std::vector<DnaSequence *> dnaSequence);

    void readfile();

    void writefile();

private:
    char *m_path_read;
    char *m_path_write;
    std::vector<DnaSequence *> m_dna_sequence;
};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_WRITEREADFILE_H
