//
// Created by Administrator on 12/26/2018.
//

#ifndef EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H
#define EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H


class Command
{
public:
    virtual void execute()=0;
};

//Dna Sequence
/*----------------------------*/
//class Light {
//
//public:
//    Light() {  }
//
//    void turnOn()
//    {
//        cout << "The light is on" << endl;
//    }
//
//    void turnOff()
//    {
//        cout << "The light is off" << endl;
//    }
//};

/*----------------------------*/

class FlipUpCommand: public Command
{
public:

    FlipUpCommand(Light& light):theLight(light)
    {

    }

    virtual void execute()
    {
        theLight.turnOn();
    }

private:
    Light& theLight;
};

/*the Command for turning off the light*/
class FlipDownCommand: public Command
{
public:
    FlipDownCommand(Light& light) :theLight(light)
    {

    }
    virtual void execute()
    {
        theLight.turnOff();
    }
private:
    Light& theLight;
};

class Switch {
public:
    Switch(Command& flipUpCmd, Command& flipDownCmd)
            :flipUpCommand(flipUpCmd),flipDownCommand(flipDownCmd)
    {

    }

    void flipUp()
    {
        flipUpCommand.execute();
    }

    void flipDown()
    {
        flipDownCommand.execute();
    }

private:
    Command& flipUpCommand;
    Command& flipDownCommand;
};



#endif //EXCELLENTEAM_EREZ_C_DNA_ANALYZER_OMAIRINO_COMMAND_H
