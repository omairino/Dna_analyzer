#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMANDPARSER_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMANDPARSER_H

#include <vector>
#include <string>

class CommandParser {
public:
     static void parser(std::string linem,std::vector<std::string> *splittedStrings);

};


#endif