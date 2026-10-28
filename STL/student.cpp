#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Employee
{
    string name;
    string contact;
    double salary;

    friend ostream &operator<<(ostream &os, const Employee &emp)
    {
        os << emp.name << "\n"
           << emp.contact << "\n"
           << emp.salary;
        return os;
    }
    friend istream &operator>>(istream &is, Employee &emp)
    {
        if (getline(is >> ws, emp.name) &&
            getline(is, emp.contact) &&
            (is >> emp.salary))
        {
        }
        return is;
    }
};
string filename = "employee.txt";
template <typename T>
class FileHandling
{
public:
    bool writeData(T data)
    {
        ofstream outFile(filename, ios::app);
        for (const auto &emp : data)
        {
            outFile << emp << endl;
        }
        outFile.close();
        cout << "Data Successfully store" << endl;
        return true;
    }

    T readData(string filename)
    {
        T datalist;
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "File is empty" << endl;
            return datalist;
        }
        typename T::value_type tempEmp;
        while (inFile >> tempEmp)
        {
            datalist.push_back(tempEmp);
        }
        inFile.close();
        return datalist;
    }
};

int main()
{
    vector<Employee> list;
    FileHandling<vector<Employee>> file;
    vector<Employee> storeData = file.readData(filename);

    for (const auto &emp : storeData)
    {

        cout << "--------------------------------------" << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Contact: " << emp.contact << endl;
        cout << "Salary: " << emp.salary << endl;
    }
    cout << "--------------------------------------" << endl;

    while (true)
    {
        char choice;
        cout << "Do you want add data(Y/N): " << endl;
        cin >> choice;

        if (choice == 'n' || choice == 'N')
            break;

        cin.ignore();

        Employee emp;

        cout << "Enter Employee Name: ";
        getline(cin, emp.name);

        cout << "Enter Employee Contact: ";
        getline(cin, emp.contact);

        cout << "Enter Employee Salary: ";
        cin >> emp.salary;

        list.push_back(emp);
    }

    file.writeData(list);

    cout << "--------------------------------------" << endl;
    for (const auto &emp : list)
    {
        cout << "Name: " << emp.name << endl;
        cout << "Contact: " << emp.contact << endl;
        cout << "Salary: " << emp.salary << endl;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}