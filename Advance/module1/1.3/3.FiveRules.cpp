/*

        Five Rules :
        If your class directly manages any resource—such as heap memory,
        file handles, or network sockets—you must explicitly define the
        following five special member functions
            To make your explanation complete, here is the quick checklist of
                those 5 functions:
            1. Destructor (~Class();) — To clean up and release the resource.
            2. Copy Constructor (Class(const Class& other);) — To make a deep
                copy of the resource.
            3. Copy Assignment Operator (Class& operator=(const Class& other);) —
                To copy resources from an existing object.
            4. Move Constructor (Class(Class&& other) noexcept;) — Introduced in
                C++11 to transfer ownership of resources without copying.
            5. Move Assignment Operator (Class& operator=(Class&& other) noexcept;) —
                Introduced in C++11 to transfer ownership from an existing object.
*/

// Rule of 5 code with Raw Pointer

#include <iostream>
#include <utility>

class DynamicArray
{
private:
    int *data;
    size_t size;

public:
    DynamicArray(size_t s)
        : size(s), data(new int[s])
    {
        std::cout << "[Constructor] Allocated: " << size << std::endl;
    }

    //---------------- RULE OF 5 STARTS HERE --------------------//
    // 1. Destructor
    ~DynamicArray()
    {
        delete[] data;
        std::cout << "[Destructor] Memory Freed!" << std::endl;
    }

    // 2. Copy Constructor
    DynamicArray(const DynamicArray &other) : size(other.size), data(new int[other.size])
    {
        std::cout << "[Copy Constructor] Deep Copy now." << std::endl;
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
        std::cout << "Deep Copy Done." << std::endl;
    }

    // 3. Copy Assignment Operator(If Object are already created.)
    DynamicArray &operator=(const DynamicArray &other)
    {
        std::cout << "[Copy Assignment] Deep Copy Assigmned." << std::endl;
        // safe for salef copy
        if (this == &other)
            return *this;
        // 2. remove old memory else it will be leak.
        delete[] data;

        // 3. allocate new memory.
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];

        return *this;
    }

    // 4. Move Constructor
    DynamicArray(DynamicArray &&other) noexcept
        : data(other.data), size(other.size)
    {
        std::cout << "[Move Constructor] Stolen resource." << std::endl;
        other.data = nullptr;
        other.size = 0;
    }

    // 5. Move Assigment Operator
    DynamicArray &operator=(DynamicArray &&other) noexcept
    {
        std::cout << "[Move Assignment] Stolen resource into existing object." << std::endl;
        // 1. check self assigment
        if (this == &other)
            return *this;

        // 2. delete self old data
        delete[] data;

        // 3. stolen pointer size
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
        return *this;
    }
    // 5 Rules are end now
};
int main()
{
    std::cout << "--- Create arr1 and arr2 ---" << std::endl;
    DynamicArray arr1(100);
    DynamicArray arr2(50);

    std::cout << "\n--- Copy Assignment ---" << std::endl;
    arr2 = arr1;
    std::cout << "\n--- Move Assignment ---" << std::endl;
    DynamicArray arr3(20);
    arr3 = std::move(arr1);
    std::cout << "\n--- End of Program ---" << std::endl;
    return 0;
}