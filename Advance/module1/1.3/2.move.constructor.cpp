#include <iostream>
#include <string>
#include <utility>
#include <memory>

class DynamicArray
{
private:
    int *data;
    size_t size;

public:
    DynamicArray(size_t s) : size(s), data(new int[s])
    {
        std::cout << "Memory Allocated for size: " << size << std::endl;
    }
    ~DynamicArray()
    {
        delete[] data;
        std::cout << "Memory Freed!" << std::endl;
    }
    DynamicArray(const DynamicArray &other) : size(other.size), data(new int[other.size])
    {
        std::cout << "Deep Copy performed." << std::endl;
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
        std::cout << "Deep Copy Done." << std::endl;
    }

    DynamicArray(DynamicArray &&other) noexcept
        : data(other.data), size(other.size)
    {
        std::cout << "Resource Stolen / Moved (Superfast)" << std::endl;
        other.data = nullptr;
        other.size = 0;
    }
};

class DynamicArray2
{
private:
    size_t size;
    std::unique_ptr<int[]> data;

public:
    DynamicArray2(size_t s) : size(s), data(std::make_unique<int[]>(s))
    {
        std::cout << "[Constructor] Allocated size: " << size << std::endl;
        if (size >= 3)
        {
            data[0] = 10;
            data[1] = 20;
            data[2] = 30;
        }
    }
    ~DynamicArray2()
    {
        if (data)
            std::cout << "[Destructor] Memory automatically freed by unique_ptr for size: " << size << std::endl;
        else
            std::cout << "[Destructor] Nothing to free, object was already moved/empty." << std::endl;
    }

    DynamicArray2(const DynamicArray2 &other)
        : size(other.size), data(std::make_unique<int[]>(other.size))
    {
        std::cout << "Deep Copy performed." << std::endl;
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];

        std::cout << "Deep Copy Done." << std::endl;
    }

    DynamicArray2(DynamicArray2 &&other) noexcept
        : size(other.size), data(std::move(other.data))
    {
        std::cout << "[Move Constructor] MOVED: without copy transfter data into unique ptr" << std::endl;
        other.size = 0;
    }

    void printFristThree() const
    {
        if (!data)
        {
            std::cout << "Array is empty / moved!" << std::endl;
            return;
        }
        std::cout << "Data: " << data[0] << ", " << data[1] << ", " << data[2] << "..." << std::endl;
    }
};

int main()
{

    // DynamicArray arr1(1000000000);
    // std::cout << "--------Copying-----------" << std::endl;
    // DynamicArray arr2 = arr1;

    // std::cout << "--------Moving-----------" << std::endl;
    // DynamicArray arr3 = std::move(arr1);

    DynamicArray2 arr1(1000000000);
    arr1.printFristThree();
    std::cout << "--------Copying-----------" << std::endl;
    DynamicArray2 arr2 = arr1;
    std::cout << "Array 1 data " << std::endl;
    arr1.printFristThree();
    std::cout << "Array 2 data " << std::endl;
    arr2.printFristThree();

    std::cout << "--------Moving-----------" << std::endl;
    DynamicArray2 arr3 = std::move(arr1);
    std::cout << "Array 1 data " << std::endl;
    arr1.printFristThree();
    std::cout << "Array 3 data " << std::endl;
    arr3.printFristThree();

    /*
        4 Steps of Move Assignment Operator
            1. Self-Assignment Check
            2. Old Resource Cleanup
            3. Steal Resource
            4. Nullify Other
            5. return *this
       */

    return 0;
}