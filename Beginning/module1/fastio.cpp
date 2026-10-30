#include <iostream>

int main()
{

    // 1. C++ streams (cin/cout) ka C language streams (scanf/printf) se connection tod diya.
    // Ab ye C ke functions ke sath coordinate nahi karenge, jisse speed bohot fast ho jayegi.
    std::ios_base::sync_with_stdio(false);

    // 2. cin aur cout ka AAPAS ka connection tod diya.
    // Ab cin input lete waqt cout ko baar-baar buffer flush karne ke liye force nahi karega.
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    // Humesha '\n' use karein taaki Fast I/O ka poora fayda mile aur TLE na aaye.
    std::cout << n << "\n";

    return 0;
}