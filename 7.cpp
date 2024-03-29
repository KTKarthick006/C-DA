#include <iostream>

class Temperature {
private:
    double celsius;

public:
    Temperature(double celsius) {
        this->celsius = celsius;
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return (celsius * 9 / 5) + 32;
    }
};

void convertTemperature(const Temperature& temp) {
    std::cout << "Temperature in Celsius: " << temp.getCelsius() << std::endl;
    std::cout << "Temperature in Fahrenheit: " << temp.getFahrenheit() << std::endl;
}

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    Temperature temp(celsius);
    convertTemperature(temp);

    return 0;
}