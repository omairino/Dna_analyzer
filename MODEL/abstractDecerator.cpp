#include "abstractDecerator.h"
std::ostream &operator<<(std::ostream &os, const IDna &dna) {

    for (size_t i = dna.m_from; i < dna.m_to; i++)
        os << dna[i];
    return os;
}