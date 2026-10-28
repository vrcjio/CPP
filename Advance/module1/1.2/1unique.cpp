#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Kingdom
{
private:
    string kingName;

public:
    Kingdom(string kingName) : kingName(kingName)
    {
        cout << "King " << kingName << " Crown is wearing." << endl;
    }
    ~Kingdom()
    {
        cout << "King " << kingName << " Kingdome life is compelete." << endl;
    }

    void status()
    {
        cout << "King " << kingName << " is rule over kingdome." << endl;
    }
};

int main()
{
    cout << "Start the game."<<endl;
        {
            unique_ptr<Kingdom> king1 = make_unique<Kingdom>("Vishnu");
            king1->status();

            // copy uniuqe pointer is created error
            // unique_ptr<Kingdom> king2 = king1;

            // but allow move the pointer
            unique_ptr<Kingdom> king2 = move(king1);
            king2->status();

            // king1->status(); null values here nullptr

        }
    cout << "End the game."<<endl;

    return 0;
}