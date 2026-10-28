#include <iostream>
#include <stdexcept>

void riskyFunction()
{
    int *data = new int[100];
    std::cout << "Memory Allote" << std::endl;

    bool errorOccurred = true;
    if (errorOccurred)
    {
        throw std::runtime_error("Run Time Error Detected.");
    }

    delete[] data;
    std::cout << "Memory are freed!" << std::endl;
}

int main()
{

    try
    {
        riskyFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error is: " << e.what() << std::endl;
    }
    return 0;
}