#include "DnaSequence.h"

Nucleotide::Nucleotide(const char nucleotide) {
    if ((nucleotide != 'A') && (nucleotide != 'G') && (nucleotide != 'C') && (nucleotide != 'T')) {
        throw std::invalid_argument("invalid Nucleotide");
    }
    m_nucleotide = nucleotide;
}

Nucleotide::Nucleotide() {}

Nucleotide::~Nucleotide() {}

char Nucleotide::getNucleotide() {
    return m_nucleotide;
}

Nucleotide &Nucleotide::operator=(const Nucleotide &other) {
    this->m_nucleotide = other.m_nucleotide;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Nucleotide &dt) {
    os << dt.m_nucleotide;
    return os;
}

