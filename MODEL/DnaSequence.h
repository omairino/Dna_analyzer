#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H

#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include "Nucleotide.h"
#include "Decerator.h"

class DnaSequence : public IDna {
public:
    DnaSequence() : m_length(0) {

    };

    DnaSequence pairing() const;

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

    DnaSequence slicing(size_t from, size_t to) const;

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &ds);

    virtual Nucleotide operator[](size_t index) const ;

    virtual size_t size() const ;

    virtual void execute() const {};

private:
    Nucleotide *m_sequence;
    size_t m_length;

};

static size_t s_id = 0;
static size_t s_name = 0;


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
