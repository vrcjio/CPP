#include <iostream>
#include <string>
#include <utility>

int main()
{

    std::string str1 = "Very Important and big data.";

    std::string str2 = str1;
    std::cout << "After Copy str1 is : " << str1 << std::endl;

    // using std::move
    std::string str3 = std::move(str1);

    std::cout << "After Move str3 is: " << str3 << std::endl;
    std::cout << "After Move str1 is: [" << str1 << "]" << std::endl;

    return 0;
}