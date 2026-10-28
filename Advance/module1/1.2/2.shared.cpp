#include <iostream>
#include <memory>
#include <string>

class Netflix : public std::enable_shared_from_this<Netflix>
{
private:
    std::string memberName;

public:
    Netflix(std::string member) : memberName(member)
    {
        std::cout << memberName << " is Login into netflix." << std::endl;
    }
    ~Netflix()
    {
        std::cout << memberName << " is Logout into netflix." << std::endl;
    }
    void status(long active_screens)
    {
        std::cout << memberName << " is active on nextflix in " << active_screens << " screens." << std::endl;
        std::cout << "Total Screen On Now : " << (shared_from_this().use_count()) - 1 << std::endl;
    }
};

int main()
{

    std::cout << "Start smartphone now " << std::endl;

    std::shared_ptr<Netflix> user1 = std::make_shared<Netflix>("Vishnu");
    user1->status(user1.use_count());
    std::cout << "Second Screen is Open now." << std::endl;
    {
        std::shared_ptr<Netflix> user2 = user1;
        user2->status(user1.use_count());
    }
    std::cout << "Second Screen is Off now." << std::endl;
    user1->status(user1.use_count());

    std::cout << "Off smartphone now " << std::endl;

    return 0;
}