#include <iostream>
#include <string>
using namespace std;

class Plant {
private:
    string name;
    int code;
    string type;
    double price;

public:
    Plant(const string& plantName, int plantCode, const string& plantType, double plantPrice) {
        name = plantName;
        code = plantCode;
        type = plantType;
        price = plantPrice;
    }

    ~Plant() {
        cout << "Destroying Plant: " << name << endl;
    }


    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Type: " << type << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
{    string plantName;
    int plantCode;
    string plantType;
    double plantPrice;

    // Read plant information from user
    cout << "Enter plant name: ";
    getline(cin, plantName);

    cout << "Enter plant code: ";
    cin >> plantCode;

    cout << "Enter plant type: ";
    cin.ignore();
    getline(cin, plantType);

    cout << "Enter plant price: ";
    cin >> plantPrice;

    // Create a Plant object using a pointer
    Plant* plantPtr = new Plant(plantName, plantCode, plantType, plantPrice);

    // Display plant information
    plantPtr->displayInfo();

    // Destroy the Plant object
    delete plantPtr;
    }
    return 0;
}