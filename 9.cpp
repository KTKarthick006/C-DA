#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer {
protected:
    string name;
    string phoneNumber;

public:
    void readData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Phone number: " << phoneNumber << endl;
    }
};

class Depositor : public Customer {
protected:
    int accountNumber;
    double balance;

public:
    void readData() {
        Customer::readData();
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter balance: ";
        cin >> balance;
    }

    void displayData() {
        Customer::displayData();
        cout << "Account number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Borrower : public Depositor {
protected:
    int loanNumber;
    double loanAmount;

public:
    void readData() {
        Depositor::readData();
        cout << "Enter loan number: ";
        cin >> loanNumber;
        cout << "Enter loan amount: ";
        cin >> loanAmount;
    }

    void displayData() {
        Depositor::displayData();
        cout << "Loan number: " << loanNumber << endl;
        cout << "Loan amount: " << loanAmount << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;

    vector<Borrower> customers(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter details for customer " << i + 1 << ":" << endl;
        customers[i].readData();
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Details of customer " << i + 1 << ":" << endl;
        customers[i].displayData();
        cout << endl;
    }

    return 0;
}