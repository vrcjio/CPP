#include <iostream>
using namespace std;

int main()
{

    int a = 10;

    int &lref = a; // left reference
    cout << "value of a = " << a << endl;
    cout << "Address of a = " << &a << endl;
    cout << "value of lref = " << lref << endl;
    cout << "Address of lref = " << &lref << endl;

    int &&rref = 20; // right refrence
    cout << "value of rref = " << rref << endl;
    cout << "Address of rref = " << &rref << endl;

    return 0;
}