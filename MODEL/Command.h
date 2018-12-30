#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H

#include "DnaSequence.h"

class Command {
public:
    virtual std::string execute() = 0;

    virtual ~Command() {};
};

/*---------------CommandSequenceCreation----------------------*/

class NewCmd : public Command {
public:
    NewCmd(std::string sequence, std::string name);

    virtual std::string execute();



    virtual ~NewCmd() {}

private:
    std::string m_sequence;
    std::string m_name;
};

class Load : public Command {
public:
    Load(std::string path ,std::string name);
    virtual std::string execute();


private:
    std::string m_path;
    std::string m_name;
};


/*---------------CommandSequenceManagement----------------------*/


class Save : public Command {
public:
    Save(std::string name,std::string pathw);

    virtual std::string execute();

private:
    std::string m_name;
    std::string m_pathw;
};

class PrintCmd : public Command {
public:
    PrintCmd(std::string key):m_key(key){}

    virtual std::string execute();

    ~PrintCmd() {}

private:
    std::string m_key;
};

#endif