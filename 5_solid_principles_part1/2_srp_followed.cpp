#include <iostream>
#include <vector>

/*
S: Single Responsibility Principle:
A class should have only one reason to change.

A class should do only one thing.

// Why?
// - Makes code easier to understand, maintain, and test.
// - Avoids classes becoming "God objects" (doing too many things).
// - Improves reusability and flexibility.
*/

/*
// 🔹 Misunderstandings about SRP (Single Responsibility Principle)

// Many people misunderstand SRP as:
// "A class should only do ONE thing"
// ❌ This is NOT fully correct.

// ✅ Correct Meaning:
// SRP = A class should have only ONE REASON TO CHANGE.

// Explanation:
// - A class may perform multiple operations, 
//   but if they all change for the SAME reason, it's fine.
// - Example: An "Invoice" class may calculateTotal(), addItem(), removeItem().
//   These are different operations, but they all belong to ONE responsibility: "Invoice management".

// Common Misunderstandings:
// 1. "SRP means one method per class" → ❌ Wrong.
// 2. "SRP means class should be very small" → ❌ Wrong.
// 3. "SRP means class should only do one operation" → ❌ Wrong.

// ✅ Correct View:
// - SRP is about **responsibility**, not size or number of methods.
// - Responsibility = reason to change.
// - If a class has multiple unrelated reasons to change → it violates SRP.

*/
using namespace std;

// Product class representing any item in eCommerce.
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

//1. ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart {
private:
    vector<Product*> products; // Store heap-allocated products

public:
    void addProduct(Product* p) { 
        products.push_back(p);
    }

    const vector<Product*>& getProducts() { 
        return products;
    } 

    //Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartPrinter(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts()) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();

    return 0;
}
