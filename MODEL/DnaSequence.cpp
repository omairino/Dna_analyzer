#include <cstring>
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
        strcpy((char *) m_sequence, (char* ) other.m_sequence);
        m_length = other.m_length;

}

DnaSequence::~DnaSequence() {
    delete[] m_sequence;
}

DnaSequence &DnaSequence::operator=(const DnaSequence &other) {
    if (this != &other && m_length!=0)
    {
        delete[] m_sequence;
        m_sequence = new Nucleotide[strlen((char *) other.m_sequence) + 1];
        strcpy((char *) m_sequence, (char* ) other.m_sequence);
        m_length = other.m_length;

    }else{

        m_sequence = new Nucleotide[strlen((char *) other.m_sequence) + 1];
        strcpy((char *) m_sequence, (char* ) other.m_sequence);
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

Nucleotide &DnaSequence::operator[](int index) const {
    return m_sequence[index];
}

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



std::map<std::string, boost::shared_ptr<DnaSequence> > Data::s_sequencekey;
std::map<std::string, boost::shared_ptr<DnaSequence> > Data::s_sequencename;
std::map<boost::shared_ptr<DnaSequence>,std::string > Data::s_status;
