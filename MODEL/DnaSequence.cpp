#include <cstring>
#include "DnaSequence.h"
DnaSequence DnaSequence::slicing(size_t from, size_t to) const {
    if (from < 0 || from > m_length || to < 0 || to > m_length || from > to) {
        std::cout << m_length << " length " << " from " << from << " to " << to << std::endl;
        throw std::invalid_argument("Invalid argument for method slice");
    }
    std::string result;
    for (size_t i = from; i < to; i++) {
        result += m_sequence[i].getNucleotide();

    }

    return DnaSequence(result);
}

DnaSequence DnaSequence::pairing() const {
    std::string result;
    for (int i = 0; i < m_length; i++) {
        if (m_sequence[i].getNucleotide() == 'T')
            result += 'A';
        else if (m_sequence[i].getNucleotide() == 'A')
            result += 'T';
        else if (m_sequence[i].getNucleotide() == 'G')
            result += 'C';
        else
            result += 'G';

    }
    return DnaSequence(result);
}

DnaSequence::DnaSequence(const char *sequence) {
    try {
        m_length = (int) (strlen(sequence));
        m_sequence = new Nucleotide[m_length];
        for (int i = 0; i < m_length; i++) {
            m_sequence[i] = Nucleotide(sequence[i]);
        }

    }
    catch (std::invalid_argument &e) {
        delete[] m_sequence;
        m_sequence = 0;
        throw;
    }
    catch (std::bad_alloc) {
        m_sequence = 0;
        throw;
    }
}

DnaSequence::DnaSequence(const std::string &sequence) {
    try {
        m_length = (int) sequence.length();
        const char *str = sequence.c_str();
        m_sequence = new Nucleotide[m_length];
        for (int i = 0; i < m_length; i++)
            m_sequence[i] = Nucleotide(str[i]);
    }
    catch (std::invalid_argument &e) {
        delete[] m_sequence;
        m_sequence = 0;
        throw;
    }
    catch (std::bad_alloc) {
        m_sequence = 0;
        throw;
    }
}

DnaSequence::DnaSequence(const DnaSequence &other) {

    m_sequence = new Nucleotide[strlen((char *) other.m_sequence) + 1];
    strcpy((char *) m_sequence, (char *) other.m_sequence);
    m_length = other.m_length;

}

DnaSequence::~DnaSequence() {
    delete[] m_sequence;
}

DnaSequence &DnaSequence::operator=(const DnaSequence &other) {
    if (this != &other && m_length != 0) {
        delete[] m_sequence;
        m_sequence = new Nucleotide[strlen((char *) other.m_sequence) + 1];
        strcpy((char *) m_sequence, (char *) other.m_sequence);
        m_length = other.m_length;

    } else {

        m_sequence = new Nucleotide[strlen((char *) other.m_sequence) + 1];
        strcpy((char *) m_sequence, (char *) other.m_sequence);
        m_length = other.m_length;
    }
    return *this;
}

DnaSequence &DnaSequence::operator=(const std::string &sequence) {
    delete[] m_sequence;
    m_length = (int) sequence.length();
    m_sequence = new Nucleotide[m_length];
    for (int i = 0; i < sequence.length(); i++)
        m_sequence[i] = Nucleotide(sequence[i]);
    return *this;

}

DnaSequence &DnaSequence::operator=(const char *sequence) {

    int length = strlen(sequence);
    delete[] m_sequence;
    m_sequence = new Nucleotide[length];
    for (int i = 0; i < length; i++)
        m_sequence[i] = Nucleotide(sequence[i]);
    m_length = length;
    return *this;
}

bool DnaSequence::operator==(const DnaSequence &ds) {

    return (m_sequence == ds.m_sequence) && (m_length == ds.m_length);
}

bool DnaSequence::operator!=(const DnaSequence &ds) {
    return !(*this == ds);
}

//Nucleotide &DnaSequence::operator[](int index) const {
//    return m_sequence[index];
//}

size_t DnaSequence::sequencelength() const {
    return m_length;;
}

std::string DnaSequence::getsequence() {
    std::string s = "";
    for (int i = 0; i < m_length; i++)
        s += m_sequence[i].getNucleotide();
    return s;
}

std::ostream &operator<<(std::ostream &os, const DnaSequence &ds) {
    for (int i = 0; i < ds.m_length; i++)
        os << ds.m_sequence[i];
    return os;
}

Nucleotide DnaSequence::operator[](size_t index) const {
    return m_sequence[index];
}

size_t DnaSequence::size() const {
    return m_length;
}



