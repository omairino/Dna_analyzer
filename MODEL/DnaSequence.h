#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H

#include <iostream>


class Nucleotide {
    char m_nucleotide;
public:
    Nucleotide(const char nucleotide);

    Nucleotide();

    ~Nucleotide();

    char getNucleotide();

    Nucleotide &operator=(const Nucleotide &other);

    friend std::ostream &operator<<(std::ostream &os, const Nucleotide &dt);
};

class DnaSequence {
public:
    DnaSequence(const char *sequence);

    DnaSequence(const std::string &sequence);

    DnaSequence(const DnaSequence &other);

    ~DnaSequence();

    DnaSequence &operator=(const DnaSequence &other);

    DnaSequence &operator=(const std::string &sequence);

    DnaSequence &operator=(const char *sequence);

    bool operator==(const DnaSequence &ds);

    bool operator!=(const DnaSequence &ds);

    Nucleotide &operator[](int index) const;

    size_t seqlength() const;

    char *getsequence();

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &ds);

private:
    Nucleotide *m_sequence;
    size_t m_length;

};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
