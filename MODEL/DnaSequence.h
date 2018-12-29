#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H

#include <iostream>
#include <vector>

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
    DnaSequence(){};

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

    size_t sequencelength() const;

    std::string getsequence();

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &ds);


private:
    Nucleotide *m_sequence;
    size_t m_length;

};

static size_t s_id = 0;
static size_t s_name = 0;
struct DNA {
    size_t id;
    std::string name;
    DnaSequence sequence;
};
class Data {
public:
    static std::vector<DNA> s_sequences;
};

#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
