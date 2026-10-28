#include <iostream>
#include <utility>

// Two diffrent Function first is Lvalue second one is Rvalue
void targetFunction(int& x)
{
    std::cout <<"Address of a in badRelay : "<<&x<<std::endl;
    std::cout << "[Target] Lvalue Data Copy: " << x << std::endl;
}

void targetFunction(int&& x)
{
    std::cout <<"Address of a in perfectRelay : "<<&x<<std::endl;
    std::cout << "[Target] Rvalue Data Stole: " << x << std::endl;
}

// -------------------------------------------------------------
// case1 std::forward problem
// -------------------------------------------------------------
template <typename T>
void badRelay(T&& arg)
{
    targetFunction(arg); 
}

// -------------------------------------------------------------
// case 1 : Perfect solution for std::forwarding
// -------------------------------------------------------------
template <typename T>
void perfectRelay(T&& arg)
{
    // std::forward 
    targetFunction(std::forward<T>(arg)); q
}

int main()
{
    int a = 50;

    std::cout <<"Address of a : "<<&a<<std::endl;

    std::cout << "--- 1. Testing badRelay ---" << std::endl;
    badRelay(a);   // Lvalue sent
    badRelay(100); // Rvalue sent

    std::cout << "\n--- 2. Testing perfectRelay ---" << std::endl;
    perfectRelay(a);   // rvalue sent
    perfectRelay(100); // lvalue sent

    return 0;
}