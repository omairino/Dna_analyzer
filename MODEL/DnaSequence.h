#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DNASEQUENCE_H

#include <iostream>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>

class Nucleotide {
    char m_nucleotide;
public:
    Nucleotide(const char nucleotide);

    Nucleotide();

    ~Nucleotide();

    char getNucleotide();

    Nucleotide &operator=(const Nucleotide &other);

    friend std::ostream &operator<<(std::ostream &os, const Nucleotide &dt);
};

class DnaSequence {
public:
    DnaSequence() : m_length(0) {

    };

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

    static std::string getAllKeysForValue(std::map<std::string, boost::shared_ptr<DnaSequence> > mapOfWords,
                                          boost::shared_ptr<DnaSequence> value) {


        std::map<std::string, boost::shared_ptr<DnaSequence> >::iterator it = mapOfWords.begin();
        // Iterate through the map
        while (it != mapOfWords.end()) {
            // Check if value of this entry matches with given value
            if (it->second == value) {
                // Push the key in given map
                return it->first;
            }
            // Go to next entry in map
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
