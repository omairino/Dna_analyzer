#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_NUCLEOTIDE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_NUCLEOTIDE_H

#include <iostream>

class Nucleotide {
    char m_nucleotide;
public:
    explicit Nucleotide(char nucleotide);

    Nucleotide();

    ~Nucleotide();

    char getNucleotide();

    Nucleotide pair() const;

    friend bool operator==(const Nucleotide &n1, const Nucleotide &n2);

    bool operator==(char nu);

    Nucleotide &operator=(char nu);

    Nucleotide &operator=(const Nucleotide &other);

    friend std::ostream &operator<<(std::ostream &os, const Nucleotide &dt);
};

bool operator==(const Nucleotide &n1, const Nucleotide &n2);


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_NUCLEOTIDE_H
