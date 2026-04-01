#include "Item.h"
#include <iostream>

using namespace std;

// constructor
Item::Item(string name, double price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
}

// mutator methods
void Item::setItemName(string name) {
    itemName = name;
}

void Item::setItemPrice(double price) {
    itemPrice = price;
}

void Item::setItemQuantity(int quantity) {
    itemQuantity = quantity;
}

// accessor methods
string Item::getItemName() const {
    return itemName;
}

double Item::getItemPrice() const {
    return itemPrice;
}

int Item::getItemQuantity() const {
    return itemQuantity;
}

// output item info
void Item::outputItemInfo() {
    cout << itemName << " " << itemQuantity
        << " @ $" << itemPrice
        << " = $" << (itemQuantity * itemPrice) << endl;
}
