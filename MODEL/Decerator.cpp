#include <sstream>
#include "Decerator.h"


std::map<std::string, char> DnaDecerator::data;

PairDecerator::PairDecerator(boost::shared_ptr<IDna> dna) : DnaDecerator(dna) {
    DnaDecerator::m_from = 0;
    DnaDecerator::m_to = size();
}

size_t PairDecerator::size() const {
    return DnaDecerator::m_dna->size();
}

Nucleotide PairDecerator::operator[](size_t index) const {

    return (*DnaDecerator::m_dna)[index].pair();
}


void PairDecerator::execute() const {
    DnaDecerator::execute();

}


Nucleotide Dnasequence::operator[](size_t index) const {
    return (*m_dna)[index];
}

size_t Dnasequence::size() const {
    return m_dna->size();
}

void Dnasequence::execute() const {
    std::cout << "start Decerator\n";
}

Dnasequence::Dnasequence(boost::shared_ptr<IDna> dna) : m_dna(dna) {

}


SliceDecerator::SliceDecerator(boost::shared_ptr<IDna> dna, size_t from, size_t to) : DnaDecerator(dna) {
    m_from = from;
    m_to = to;

}

void SliceDecerator::execute() const {
    DnaDecerator::execute();
    if (m_from < 0 || m_from > size() || m_to < 0 || m_to > size() || m_from > m_to) {
        std::cout << size() << " length " << " from " << m_from << " to " << m_to << std::endl;
        throw std::invalid_argument("Invalid argument for method slice");
    }
}

size_t SliceDecerator::size() const {
    return m_to - m_from;
}

Nucleotide SliceDecerator::operator[](size_t index) const {
    return (*DnaDecerator::m_dna)[index];
}

DnaDecerator::DnaDecerator(boost::shared_ptr<IDna> dna) : m_dna(dna) {
}


ReplaceDecerator::ReplaceDecerator(boost::shared_ptr<IDna> dna, std::map<std::string, char> data) : DnaDecerator(
        dna) {
    DnaDecerator::data = data;
}

size_t ReplaceDecerator::size() const {
    return DnaDecerator::m_dna->size();
}

Nucleotide ReplaceDecerator::operator[](size_t index) const {
    std::ostringstream s;

    s << (index);
    if (DnaDecerator::data.find(s.str()) != DnaDecerator::data.end()) {
        char b = DnaDecerator::data.find(s.str())->second;
        return (*DnaDecerator::m_dna)[index].replace(b);
    }
    return (*DnaDecerator::m_dna)[index];
}

void ReplaceDecerator::execute() const {
    DnaDecerator::execute();
}

ConcatDecerator::ConcatDecerator(std::vector<boost::shared_ptr<IDna> > &data) : m_data(data), DnaDecerator(data[0]) {
}

size_t ConcatDecerator::size() const {
    size_t size = 0;

    for (size_t i = 0; i < m_data.size(); i++) {
        size += m_data[i]->size();
    }
    return size;
}

Nucleotide ConcatDecerator::operator[](size_t index) const {
    
    return DnaDecerator::operator[](index);
}

void ConcatDecerator::execute() const {
    DnaDecerator::execute();
}
