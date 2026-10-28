#include <iostream>
#include <string>

using namespace std;

class ToyRobot
{
private:
    string robotName;

public:
    ToyRobot(string robotName) : robotName(robotName)
    {
        cout << "robot " << robotName << " is start now." << endl;
    }
    ~ToyRobot()
    {
        cout << "robot " << robotName << " is off now. for power saving." << endl;
    }
    void doDance()
    {
        cout << "robot " << robotName << " is dance now." << endl;
    }
};

int main()
{
    cout << "Open room door."<<endl;
    {
        ToyRobot myRobot("Megatrone");
        myRobot.doDance();
    }
    {
        ToyRobot* myRobot = new ToyRobot("IronMan");
        myRobot->doDance();
        delete myRobot; 
        /* ye problem hai agar delete lagana bhul jaye developer to kabhi
            object delete hi nahi hota hai last of the program tk ya uske 
            bad bhi.
            Isi problem ka solution 1.2.cpp programm me hai
        */
    }
    cout << "Room Door Off" << endl;

    return 0;
}