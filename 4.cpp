#include <iostream>

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
    std::cout << "Enter a number: ";
    std::cin >> n;

    Number number(n);
    Number copy(number);

    if (copy.isPrime()) {
        std::cout << "The number is prime." << std::endl;
    } else {
        std::cout << "The number is not prime." << std::endl;
    }

    return 0;
}