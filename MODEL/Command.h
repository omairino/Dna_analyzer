#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H

#include "DnaSequence.h"
#include "DATA.h"
class Command {
public:
    virtual std::string execute(std::vector<std::string> data) = 0;

    virtual ~Command() {};
};

/*---------------CommandSequenceCreation----------------------*/

class NewCmd : public Command {
public:
    NewCmd() {}

    virtual std::string execute(std::vector<std::string> data);

    void parsing(std::vector<std::string> &data);

    virtual ~NewCmd() {}

private:
    std::string m_sequence;
    std::string m_name;
};

class Load : public Command {
public:
    Load() {}

    void parsing(std::vector<std::string> &data);

    virtual std::string execute(std::vector<std::string> data);


private:
    std::string m_path;
    std::string m_name;
};

//
//class Dup : public Command {
//public:
//    Dup() {}
//
//    void parsing(std::vector<std::string> &data);
//
//    virtual std::string execute(std::vector<std::string> data);
//
//
//private:
//    std::string m_sequence;
//    std::string m_name;
//};

/*------------------------------------- Sequence Manipulation--------------------------------*/

class Pair : public Command {
public:
    Pair() {}

    virtual std::string execute(std::vector<std::string> data);

    void parsing(std::vector<std::string> &data);

    virtual ~Pair() {};
    static size_t m_id;
private:
    std::string m_name;
    std::string m_sequence;
    std::string m_key;
};


class Slice : public Command {
public:
    Slice() {}

    virtual std::string execute(std::vector<std::string> data);

    void parsing(std::vector<std::string> &data);

    virtual ~Slice() {};
    static size_t m_id;
private:

    std::string m_name;
    std::string m_sequence;
    std::string m_key;

};

class Replace : public Command {
public:
    Replace() {}

    virtual std::string execute(std::vector<std::string> data);

    int parsing(std::vector<std::string> &data);

    virtual ~Replace() {};
    static size_t m_id;
private:

    std::string m_name;
    std::string m_key;

};


class Concat : public Command {
public:
    Concat() {

    }

    virtual std::string execute(std::vector<std::string> data);

    int parsing(std::vector<std::string> &data);

    virtual ~Concat() {};
    static size_t m_id;
private:

    std::vector<boost::shared_ptr<IDna> > m_sequences;
    std::string m_name;
    std::string m_key;

};


/*------------------------------------- End Sequence Manipulation!!--------------------------------*/
/*-------------------------------------------Sequence Management--------------------------------*/

class Rename : public Command {
public:
    Rename() {}

    virtual std::string execute(std::vector<std::string> data);

    virtual ~Rename() {};
    static size_t m_id;
private:

    std::string m_name;

};

class Delete : public Command {
public:
    Delete() {}

    virtual std::string execute(std::vector<std::string> data);

    void parsing(std::vector<std::string> &data);

    virtual ~Delete() {};
    static size_t m_id;

};

///*----------------------------------------End Sequence Management!!--------------------------------*/
//
//
///*---------------CommandSequenceManagement----------------------*/
//
//
class Save : public Command {
public:
    Save() {}


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


/*----------------------------------------Sequence Analysis Commands--------------------------------*/

class Len : public Command {
public:
    Len() {}

    virtual std::string execute(std::vector<std::string> data);

    virtual ~Len() {};

};

#endif