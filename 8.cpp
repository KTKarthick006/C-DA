#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Item {
protected:
    int itemNo;
    string name;
    double price;

public:
    Item(int itemNo, const string& name, double price)
        : itemNo(itemNo), name(name), price(price) {}

    virtual double calculateBill() const {
        return price;
    }

    virtual void display() const {
        cout << "Item No: " << itemNo << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
    }
};

class DiscountedItem : public Item {
private:
    double discountPercent;

public:
    DiscountedItem(int itemNo, const string& name, double price, double discountPercent)
        : Item(itemNo, name, price), discountPercent(discountPercent) {}

    double calculateBill() const override {
        double discountedPrice = price - (price * discountPercent / 100);
        return discountedPrice;
    }

    void display() const override {
        Item::display();
        cout << "Discount Percent: " << fixed << setprecision(2) << discountPercent << "%" << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item*> items;

    for (int i = 0; i < n; i++) {
        int itemNo;
        string name;
        double price;
        double discountPercent;

        cout << "Enter details for item " << i + 1 << ":" << endl;
        cout << "Item No: ";
        cin >> itemNo;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Price: $";
        cin >> price;
        cout << "Discount Percent: ";
        cin >> discountPercent;

        Item* item = new DiscountedItem(itemNo, name, price, discountPercent);
        items.push_back(item);
    }

    cout << endl << "Item-wise bill:" << endl;
    double totalAmount = 0.0;

    for (const auto& item : items) {
        item->display();
        double bill = item->calculateBill();
        cout << "Bill: $" << fixed << setprecision(2) << bill << endl;
        totalAmount += bill;
        cout << endl;
    }

    cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount << endl;

    for (const auto& item : items) {
        delete item;
    }

    return 0;
}