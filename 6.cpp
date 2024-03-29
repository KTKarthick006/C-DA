#include <iostream>
#include <string>
using namespace std;

class FDAccount {
private:
    int fdno;
    string name;
    double amt;
    double interestRate;
    double maturityAmt;
    int numMonths;

public:
    FDAccount(int fdno, string name, double amt, int numMonths, double interestRate = 5.0) {
        this->fdno = fdno;
        this->name = name;
        this->amt = amt;
        this->numMonths = numMonths;
        this->interestRate = interestRate;
        calculateMaturityAmt();
    }

    void calculateMaturityAmt() {
        maturityAmt = amt + (amt * interestRate * numMonths) / 100;
    }

    void displayDetails() {
        cout << "FD Account Details:" << endl;
        cout << "FD Number: " << fdno << endl;
        cout << "Name: " << name << endl;
        cout << "Amount: " << amt << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Number of Months: " << numMonths << endl;
        cout << "Maturity Amount: " << maturityAmt << endl;
    }
};

int main() {
    FDAccount account(12345, "Karthick", 10000, 12);
    account.displayDetails();

    return 0;
}