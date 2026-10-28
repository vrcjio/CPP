#include<iostream>
#include<vector>
#include<array>
#include<memory_resource>

int main(){

    //ready 512bytes box on stack... Buffer
    std::array<std::byte, 512> stackBuffer;

    std::pmr::monotonic_buffer_resource memPool(
        stackBuffer.data(),
        stackBuffer.size()
    );

    std::pmr::vector<int> vec(&memPool);

    for (int i = 1; i <= 5; ++i)
    {
        vec.push_back(i * 10);
    }

    std::cout << "PMR Vector elements: ";
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl; 
    
    std::cout << "Size of one Element: "<<sizeof(vec[0])<<"Bytes"<<std::endl;
    std::cout << "Base address of: "<<(void*)stackBuffer.data()<<std::endl;
    std::cout << "PMR Vector elements address: ";
    for (const int &num : vec)
    {
        std::cout << &num << " ";
    }
    std::cout << std::endl;

    return 0;
}