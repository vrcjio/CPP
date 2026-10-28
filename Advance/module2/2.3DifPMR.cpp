#include <iostream>
#include <vector>
#include <array>
#include <memory_resource>

/*
    [Heap vs PMR Stack Allocation - Core Concept]

    1. Normal Vector (Without PMR / Heap):
       - Memory andar se 100% continuous (contiguous) hi rehti hai.
       - Par jab bhi naye elements ke liye memory mangni ya resize karni hoti hai,
         to program OS ke memory manager (malloc / new) ko call karta hai.
       - OS free memory search karta hai aur locks lagata hai, jisme hazaaron CPU cycles
         aur latency waste hoti hai. Saath hi heap fragmentation ka risk rehta hai.

    2. PMR Vector (With PMR monotonic_buffer_resource / Stack):
       - Memory yahan bhi 100% continuous (contiguous) hi rehti hai.
       - Par ye OS ke paas bilkul nahi jata; stack par pehle se bane buffer me se
         sirf ek internal pointer ko aage khiska deta hai (Bump Allocation).
       - Isme sirf 1-2 CPU cycles lagti hain (Zero OS System Calls & Zero Overhead).
*/

int main()
{
    int stackReferenceVariable = 0;
    std::cout << "=== 1. Memory References ===" << std::endl;
    std::cout << "[Stack Reference Address]: " << &stackReferenceVariable << std::endl;

    // PMR
    std::array<std::byte, 512> stackBuffer;
    std::cout << "[PMR Stack Buffer Range ]: "
              << static_cast<void *>(stackBuffer.data()) << " to "
              << static_cast<void *>(stackBuffer.data() + stackBuffer.size())
              << std::endl;

    std::pmr::monotonic_buffer_resource memPool(stackBuffer.data(), stackBuffer.size());

    // 3. PMR Vector 5 memory reserved on stack
    std::pmr::vector<int> pmrVec(&memPool);
    pmrVec.reserve(5);

    // 4. Normal Vector // 5 memory in heap
    std::vector<int> heapVec;
    heapVec.reserve(5);

    // -------------------------------------------------------------
    // PMR Vector (on Stack Memory)
    // -------------------------------------------------------------
    std::cout << "\n=== 2. PMR Vector (Allocated from Stack Buffer) ===" << std::endl;
    int *pmrData = pmrVec.data();
    std::cout << "PMR Vector Buffer Start: " << pmrData << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "  Slot [" << i << "] Address: " << (pmrData + i) << std::endl;
    }

    // -------------------------------------------------------------
    // Normal Vector (Heap Memory)
    // -------------------------------------------------------------
    std::cout << "\n=== 3. Normal Vector (Allocated from OS Heap) ===" << std::endl;
    int *heapData = heapVec.data();
    std::cout << "Heap Vector Buffer Start: " << heapData << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "  Slot [" << i << "] Address: " << (heapData + i) << std::endl;
    }

    // -------------------------------------------------------------
    // Comparison
    // -------------------------------------------------------------
    std::cout << "\n=== 4. Analysis ===" << std::endl;
    std::cout << "PMR Slots Contiguous Difference : "
              << reinterpret_cast<char *>(pmrData + 1) - reinterpret_cast<char *>(pmrData)
              << " Bytes" << std::endl;

    std::cout << "Heap Slots Contiguous Difference: "
              << reinterpret_cast<char *>(heapData + 1) - reinterpret_cast<char *>(heapData)
              << " Bytes" << std::endl;

    return 0;
}