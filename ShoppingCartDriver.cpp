#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "DateUtility.h"
#include "Item.h"

using namespace std;

char getMenuChoice();
void processMenuChoice(char choice, ShoppingCart& theCart);

int main() {
    string custName;
    char choice;

    cout << "**** Shopping Cart ****" << endl << endl;

    cout << "Enter customer's name: ";
    getline(cin, custName);
    cout << endl;

    ShoppingCart theCart(custName);

    cout << "Customer Name: " << theCart.getCustomerName()
        << "   Today's Date: " << theCart.getCurrentDate() << endl;

    choice = getMenuChoice();

    while (choice != 'q') {
        processMenuChoice(choice, theCart);
        choice = getMenuChoice();
    }

    return 0;
}

char getMenuChoice() {
    string menuOptions = "adcpoq";
    char choice = ' ';

    cout << " -- Online Shopping Menu --" << endl;
    cout << "        a - Add item to cart" << endl;
    cout << "        d - Remove item from cart" << endl;
    cout << "        c - Change item quantity" << endl;
    cout << "        p - Change item price" << endl;
    cout << "        o - Output shopping cart" << endl;
    cout << "        q - Quit" << endl;
    cout << endl;
    cout << "        Choose option: ";

    cin >> choice;
    cin.ignore();

    while (menuOptions.find(choice) == string::npos) {
        cout << "        Invalid option. Enter a new option: ";
        cin >> choice;
        cin.ignore();
    }

    return choice;
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
    string name = "";
    double price = 0.0;
    int quantity = 0;

    switch (choice) {
    case 'a':
        cout << " -- Add Item to Cart --" << endl;
        cout << "        Enter the item name: ";
        getline(cin, name);
        cout << "        Enter the item price: ";
        cin >> price;
        cout << "        Enter the item quantity: ";
        cin >> quantity;
        cin.ignore();

        theCart.addItemToCart(Item(name, price, quantity));
        cout << endl;
        cout << "        >>> Item " << name << " added to cart <<<" << endl;
        break;

    case 'd':
        cout << " -- Remove Item from Cart --" << endl;
        cout << "        Enter the item name: ";
        getline(cin, name);

        theCart.removeItemFromCart(name);
        break;

    case 'c':
        cout << " -- Change Item Quantity --" << endl;
        cout << "        Enter the item name: ";
        getline(cin, name);
        cout << "        Enter the new quantity: ";
        cin >> quantity;
        cin.ignore();

        theCart.changeItemQuantity(name, quantity);
        break;

    case 'p':
        cout << " -- Change Item Price --" << endl;
        cout << "        Enter the item name: ";
        getline(cin, name);
        cout << "        Enter the new price: ";
        cin >> price;
        cin.ignore();

        theCart.changeItemPrice(name, price);
        break;

    case 'o':
        theCart.outputCartInfo();
        break;
    }

    cout << endl;
}



