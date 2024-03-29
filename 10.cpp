#include <iostream>
#include <string>

using namespace std;

class Worker {
protected:
    int code;
    string name;
    float salary;

public:
    Worker(int code, string name, float salary) {
        this->code = code;
        this->name = name;
        this->salary = salary;
    }
};

class Officer : public Worker {
protected:
    float DA;
    float HRA;

public:
    Officer(int code, string name, float salary, float DA, float HRA) : Worker(code, name, salary) {
        this->DA = DA;
        this->HRA = HRA;
    }
};

class Manager : public Officer {
protected:
    float TA;
    float grossSalary;

public:
    Manager(int code, string name, float salary, float DA, float HRA, float TA) : Officer(code, name, salary, DA, HRA) {
        this->TA = TA;
        calculateGrossSalary();
    }

    void calculateGrossSalary() {
        grossSalary = salary + DA + HRA + TA;
    }

    void printDetails() {
        cout << "Manager Details:" << endl;
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "TA: " << TA << endl;
        cout << "Gross Salary: " << grossSalary << endl;
    }
};

int main() {
    Manager manager(1234, "Karthick", 50000, 10000, 500, 500);
    manager.printDetails();

    return 0;
}