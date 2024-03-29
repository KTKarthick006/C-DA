#include <iostream>
using namespace std;

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
    cout << "Temperature in Celsius: " << temp.getCelsius() << endl;
    cout << "Temperature in Fahrenheit: " << temp.getFahrenheit() << endl;
}

int main() {
    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    Temperature temp(celsius);
    convertTemperature(temp);

    return 0;
}