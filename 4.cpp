#include <iostream>
using namespace std;


class Number {
private:
    int num;

public:
    Number(int n) {
        num = n;
    }

    Number(const Number& other) {
        num = other.num;
    }

    bool isPrime() {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Number number(n);
    Number copy(number);

    if (copy.isPrime()) {
        cout << "The number is prime." << endl;
    } else {
        cout << "The number is not prime." << endl;
    }

    return 0;
}