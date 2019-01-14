#include "Nucleotide.h"


Nucleotide::Nucleotide(char nucleotide) {
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


Nucleotide Nucleotide::pair() const {
    char result;
    if (m_nucleotide == 'T')
        result = 'A';
    else if (m_nucleotide == 'A')
        result = 'T';
    else if (m_nucleotide == 'G')
        result = 'C';
    else
        result = 'G';

    return Nucleotide(result);
}

bool operator==(const Nucleotide &n1, const Nucleotide &n2) {
    if (n1.m_nucleotide == n2.m_nucleotide) {
        return true;
    }
    return false;
}

bool Nucleotide::operator==(char nu) {
    return m_nucleotide == nu;
}

Nucleotide &Nucleotide::operator=(char nu) {
    m_nucleotide = nu;
    return *this;
}
