
#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DECERATOR_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DECERATOR_H

#include "DnaSequence.h"

struct IDna {
    virtual Nucleotide operator[](size_t index) const = 0;

    virtual ~IDna() {}

    virtual size_t size() const = 0;

    virtual void execute() const = 0;
};


class DnaDecerator : public IDna {
public:
    DnaDecerator(boost::shared_ptr<IDna> dna);

    virtual Nucleotide operator[](size_t index) const {}

    virtual ~DnaDecerator() {}

    virtual size_t size() const {}

    virtual void execute() const {
        m_dna->execute();
    }

    boost::shared_ptr<IDna> m_dna;
    size_t m_from;
    size_t m_to;
};

std::ostream &operator<<(std::ostream &os, const IDna &dna);

class Dnasequence : public IDna {
public:
    boost::shared_ptr<DnaSequence> m_dna;

    Dnasequence(boost::shared_ptr<DnaSequence> dna);

    virtual Nucleotide operator[](size_t index) const;

    virtual size_t size() const;

    virtual void execute() const;
};

class PairDecerator : public DnaDecerator {

public:
    explicit PairDecerator(boost::shared_ptr<IDna> dna);

    virtual size_t size() const;

    virtual Nucleotide operator[](size_t index) const;

    virtual void execute() const;


};

class SliceDecerator : public DnaDecerator {

public:
    SliceDecerator(boost::shared_ptr<IDna> dna, size_t from, size_t to);

    virtual size_t size() const;

    virtual Nucleotide operator[](size_t index) const;

    virtual void execute() const;


};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DECERATOR_H
