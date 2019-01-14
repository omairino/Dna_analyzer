#include "Decerator.h"

PairDecerator::PairDecerator(boost::shared_ptr<IDna> dna) : DnaDecerator(dna) {
    DnaDecerator::m_from=0;
    DnaDecerator::m_to=size();
}

size_t PairDecerator::size() const {
    return DnaDecerator::m_dna->size();
}

Nucleotide PairDecerator::operator[](size_t index) const {

    return (*DnaDecerator::m_dna)[index].pair();
}





void PairDecerator::execute() const {
    DnaDecerator::execute();
    std::cout << *DnaDecerator::m_dna << std::endl;
}

Dnasequence::Dnasequence(boost::shared_ptr<DnaSequence> dna) : m_dna(dna) {

}

Nucleotide Dnasequence::operator[](size_t index) const {
    return (*m_dna)[index];
}

size_t Dnasequence::size() const {
    return m_dna->sequencelength();
}

void Dnasequence::execute() const {
    std::cout << "start Decerator\n";
}


SliceDecerator::SliceDecerator(boost::shared_ptr<IDna> dna, size_t from, size_t to) : DnaDecerator(dna){
    DnaDecerator::m_from=from;
    DnaDecerator::m_to=to;

}

void SliceDecerator::execute() const {
    DnaDecerator::execute();
    if (m_from < 0 || m_from > size() || m_to < 0 || m_to > size() || m_from > m_to) {
        std::cout << size() << " length " << " from " << m_from << " to " << m_to << std::endl;
        throw std::invalid_argument("Invalid argument for method slice");
    }
}

size_t SliceDecerator::size() const {
    return DnaDecerator::m_dna->size();
}

Nucleotide SliceDecerator::operator[](size_t index) const {
    return (*DnaDecerator::m_dna)[index];
}

DnaDecerator::DnaDecerator(boost::shared_ptr<IDna> dna) : m_dna(dna) {
}


std::ostream &operator<<(std::ostream &os, const IDna &dna) {
    for (int i = 0; i < dna.size(); i++)

        os << dna[i];

    return os;
}