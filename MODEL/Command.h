#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H

#include "DnaSequence.h"

class Command {
public:
    virtual std::string execute()=0;
    virtual ~Command(){};
};

/*---------------CommandSequenceCreation----------------------*/

class NewCmd : public Command {
public:
    NewCmd(std::string sequence, std::string name);

    virtual std::string execute();
    virtual ~NewCmd(){}

private:
    DnaSequence m_sequence;
    std::string m_name;
};

class Load : public Command {
public:
    Load(DnaSequence sequence);

    virtual std::string execute();

private:
    DnaSequence m_sequence;
};


/*---------------CommandSequenceManagement----------------------*/

//
//class Save : public Command {
//public:
//    Save();
//
//    virtual std::string execute() {}
//
//private:
//
//};
//
class PrintCmd : public Command {
public:
    PrintCmd(){}
    virtual std::string execute();
    ~PrintCmd(){}

private:
};
#endif