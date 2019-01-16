//
// Created by omairino on 1/15/19.
//

#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_ABSTRACTDECERATOR_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_ABSTRACTDECERATOR_H

#include "Nucleotide.h"

struct IDna {
    virtual Nucleotide operator[](size_t index) const = 0;

    virtual ~IDna() {}

    virtual size_t size() const = 0;

    size_t m_from;
    size_t m_to;
    friend  std::ostream &operator<<(std::ostream &os, const IDna &dna);
};


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_ABSTRACTDECERATOR_H
