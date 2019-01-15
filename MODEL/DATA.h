
#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DATA_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DATA_H
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <map>
#include "Decerator.h"
class Data {
public:


    static std::map<std::string, boost::shared_ptr<IDna> > s_sequencekey;
    static std::map<std::string, boost::shared_ptr<IDna> > s_sequencename;
    static std::map<boost::shared_ptr<IDna>, std::string> s_status;

    static std::string getAllKeysForValue(std::map<std::string, boost::shared_ptr<IDna> > mapOfWords,
                                          boost::shared_ptr<IDna> value) {
        std::map<std::string, boost::shared_ptr<IDna> >::iterator it = mapOfWords.begin();
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


#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_DATA_H
