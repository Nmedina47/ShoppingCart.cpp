#include "ShoppingCart.h"
#include "DateUtility.h"
#include <iostream>

using namespace std;

ShoppingCart::ShoppingCart(string name) {
    customerName = name;
    currentDate = getDateString();
}

string ShoppingCart::getCustomerName() const {
    return customerName;
}

string ShoppingCart::getCurrentDate() const {
    return currentDate;
}

int ShoppingCart::getItemCount() const {
    int total = 0;

    for (int i = 0; i < cart.size(); i++) {
        total += cart[i].getItemQuantity();
    }

    return total;
}

int ShoppingCart::findItemInCart(string name) {
    for (int i = 0; i < cart.size(); i++) {
        if (cart[i].getItemName() == name) {
            return i;
        }
    }

    return cart.size();
}

void ShoppingCart::addItemToCart(Item item) {
    int index = findItemInCart(item.getItemName());

    if (index < cart.size()) {
        cout << "Item already in cart. Nothing added." << endl;
    }
    else {
        cart.push_back(item);
        cout << "Item added." << endl;
    }
}

void ShoppingCart::changeItemQuantity(string name, int quantity) {
    int index = findItemInCart(name);

    if (index == cart.size()) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
    else {
        cart[index].setItemQuantity(quantity);
        cout << "Item quantity updated." << endl;
    }
}

void ShoppingCart::changeItemPrice(string name, double price) {
    int index = findItemInCart(name);

    if (index == cart.size()) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
    else {
        cart[index].setItemPrice(price);
        cout << "Item price updated." << endl;
    }
}

void ShoppingCart::removeItemFromCart(string name) {
    int index = findItemInCart(name);

    if (index == cart.size()) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
    else {
        cart.erase(cart.begin() + index);
        cout << "Item removed." << endl;
    }
}

void ShoppingCart::outputCartInfo() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << getItemCount() << endl << endl;

    if (cart.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (int i = 0; i < cart.size(); i++) {
            cart[i].outputItemInfo();
        }
    }
}
