#include <iostream>
#include <stdexcept>
#include <memory>

void safeFunction()
{
    std::unique_ptr<int[]> data = std::make_unique<int[]>(100);
    std::cout << "Smart pointer allocate memory." << std::endl;

    bool errorOccurred = true;
    if (errorOccurred)
    {
        throw std::runtime_error("Runtime Error Detected.");
    }
    // auto delete no need delete
}

int main()
{
    try
    {
        safeFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error is: " << e.what() << std::endl;
    }
    return 0;
}