#include <iostream>

struct Tracker
{
    int value;
    Tracker(int v) : value(v)
    {
        std::cout << "Temporary Object Created address: " << this << std::endl;
    }
    ~Tracker()
    {
        std::cout << "Temporary Object Created address: " << this << std::endl;
    }
};

void checkAddress(Tracker &&t)
{
    std::cout << "Inside of function address of t: " << &t << std::endl;
}
int main()
{
    std::cout << "----Before function call------------" << std::endl;
    checkAddress(Tracker(100));
    std::cout << "----After Function call-------------" << std::endl;
    return 0;
}