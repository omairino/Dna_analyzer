#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H

#include "DnaSequence.h"

class Command {
public:
    virtual std::string execute(std::vector<std::string> data) = 0;

    virtual ~Command() {};
};

/*---------------CommandSequenceCreation----------------------*/

class NewCmd : public Command {
public:
    NewCmd() {}

    NewCmd(std::vector<std::string> data);

    virtual std::string execute(std::vector<std::string> data);


    virtual ~NewCmd() {}

private:
    std::string m_sequence;
    std::string m_name;
};

class Load : public Command {
public:
    Load() {}

    Load(std::vector<std::string> data);

    virtual std::string execute(std::vector<std::string> data);


private:
    std::string m_path;
    std::string m_name;
};


/*---------------CommandSequenceManagement----------------------*/


class Save : public Command {
public:
    Save() {}

    Save(std::vector<std::string> data);

    virtual std::string execute(std::vector<std::string> data);

private:
    std::string m_name;
    std::string m_pathw;
};

class PrintCmd : public Command {
public:
    PrintCmd() {}

    PrintCmd(std::vector<std::string> data) : m_key(data[1]) {}

    virtual std::string execute(std::vector<std::string> data);

    ~PrintCmd() {}

private:
    std::string m_key;
};


class List : public Command {
public:
    List() {}

    virtual std::string execute(std::vector<std::string> data);

    ~List() {}

};


class Pair: public Command {
public:
    Pair(){

    }
    virtual std::string execute(std::vector<std::string> data);

    virtual ~Pair() {};
    static size_t m_id;
private:

    std::string m_name;
    std::string m_sequence;

};


class Slice: public Command {
public:
    Slice(){

    }
    virtual std::string execute(std::vector<std::string> data);

    virtual ~Slice() {};
    static size_t m_id;
private:

    std::string m_name;
    std::string m_sequence;

};

#endif