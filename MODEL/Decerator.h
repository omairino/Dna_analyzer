
#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DECERATOR_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DECERATOR_H

#include "abstractDecerator.h"
#include <boost/shared_ptr.hpp>
#include <map>
#include <vector>


class DnaDecerator : public IDna {
public:
    DnaDecerator(boost::shared_ptr<IDna> dna);

    virtual Nucleotide operator[](size_t index) const {}

    virtual ~DnaDecerator() {}

    virtual size_t size() const {}


    boost::shared_ptr<IDna> m_dna;
    std::vector<boost::shared_ptr<IDna> > datas;
    static std::map<std::string, char> data;

};


class PairDecerator : public DnaDecerator {

public:
    explicit PairDecerator(boost::shared_ptr<IDna> dna);

    virtual size_t size() const;

    virtual Nucleotide operator[](size_t index) const;


};

class SliceDecerator : public DnaDecerator {

public:
    SliceDecerator(boost::shared_ptr<IDna> dna, size_t from, size_t to);

    virtual size_t size() const;

    virtual Nucleotide operator[](size_t index) const;


};

class ReplaceDecerator : public DnaDecerator {

public:
    ReplaceDecerator(boost::shared_ptr<IDna> dna, std::map<std::string, char> data);

    virtual size_t size() const;

    virtual Nucleotide operator[](size_t index) const;


};

class ConcatDecerator : public DnaDecerator {

public:
    ConcatDecerator(std::vector<boost::shared_ptr<IDna> > &data);

    virtual size_t size() const;

    virtual Nucleotide operator[](size_t index) const;


private:
    std::vector<boost::shared_ptr<IDna> > m_data;
    std::vector<size_t> m_sizes;
    size_t m_size;

};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DECERATOR_H
