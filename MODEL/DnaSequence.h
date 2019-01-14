#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H

#include <iostream>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include "Nucleotide.h"


class DnaSequence {
public:
    DnaSequence() : m_length(0) {

    };

    DnaSequence pairing() const;

    DnaSequence(const char *sequence);

    DnaSequence(const std::string &sequence);

    DnaSequence(const DnaSequence &other);

    ~DnaSequence();


    DnaSequence &operator=(const DnaSequence &other);

    DnaSequence &operator=(const std::string &sequence);

    DnaSequence &operator=(const char *sequence);

    bool operator==(const DnaSequence &ds);

    bool operator!=(const DnaSequence &ds);

    Nucleotide &operator[](int index) const;

    size_t sequencelength() const;

    std::string getsequence();
    DnaSequence slicing(size_t from, size_t to) const;

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &ds);


private:
    Nucleotide *m_sequence;
    size_t m_length;

};

static size_t s_id = 0;
static size_t s_name = 0;


class Data {
public:

    static std::map<std::string, boost::shared_ptr<DnaSequence> > s_sequencekey;
    static std::map<std::string, boost::shared_ptr<DnaSequence> > s_sequencename;
    static std::map<boost::shared_ptr<DnaSequence>, std::string> s_status;

    static std::string getAllKeysForValue(std::map<std::string, boost::shared_ptr<DnaSequence> > mapOfWords,
                                          boost::shared_ptr<DnaSequence> value) {
        std::map<std::string, boost::shared_ptr<DnaSequence> >::iterator it = mapOfWords.begin();
        while (it != mapOfWords.end()) {
            if (it->second == value) {
                return it->first;
            }
            it++;
        }
        return "";
    }


    static bool checkSameName(std::string m_name) {
        if (Data::s_sequencename.find(m_name) != Data::s_sequencename.end()) {
            return true;
        }

        return false;
    }
};

#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
