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








SliceDecerator::SliceDecerator(boost::shared_ptr<IDna> dna, size_t from, size_t to) : DnaDecerator(dna) {
    m_from = from;
    m_to = to;

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



ConcatDecerator::ConcatDecerator(std::vector<boost::shared_ptr<IDna> > &data) : m_data(data), DnaDecerator(data[0]) {

    for (size_t i = 0; i < m_data.size(); i++) {
        m_size += m_data[i]->size();
    }

}

size_t ConcatDecerator::size() const {
    return m_size;
}

Nucleotide ConcatDecerator::operator[](size_t index) const {
    size_t size = 0;
    size_t size1 = 0;
    size_t n;
    for (size_t i = 0; i < m_data.size(); i++) {
        size += m_data[i]->size();
        if (size > index) {
            n = i;
            break;
        }
        size1 += m_data[i]->size();
    }
    return (*m_data[n])[index-size1];
}

