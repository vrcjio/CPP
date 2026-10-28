#include <iostream>
#include <memory>
#include <string>

class Girl;
class Boy;

class Girl
{
public:
    std::string name;
    std::shared_ptr<Boy> boyFriend;

    Girl(std::string name) : name(name)
    {
        std::cout << name << " is comming now. " << std::endl;
    }
    ~Girl()
    {
        std::cout << name << " is going. " << std::endl;
    }
};
class Boy
{
public:
    std::string name;
    std::shared_ptr<Girl> girlFriend;

    Boy(std::string name) : name(name)
    {
        std::cout << name << " is comming now. " << std::endl;
    }
    ~Boy()
    {
        std::cout << name << " is going. " << std::endl;
    }
};

int main()
{

    std::cout << "Start Game" << std::endl;

    {
        std::shared_ptr<Boy> vishnu = std::make_shared<Boy>("Vishnu");
        std::shared_ptr<Girl> urmila = std::make_shared<Girl>("Urmila");

        //remove bellon two line and check output.
        vishnu->girlFriend = urmila;
        urmila->boyFriend = vishnu;

        std::cout << "Vishnu user count is: " << vishnu.use_count() << std::endl;
        std::cout << "Urmila user count is: " << urmila.use_count() << std::endl;
    }

    std::cout << "End Game" << std::endl;

    return 0;
}