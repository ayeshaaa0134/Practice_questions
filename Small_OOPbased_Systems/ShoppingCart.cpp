#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int stockQuantity;

public:
    Product(int id = 0, const string& n = "", double p = 0.0, int sq = 0)
        : productId(id), name(n) {
        setPrice(p);
        setStockQuantity(sq);
    }

    int getProductId() const { return productId; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }

    void setProductId(int id) { productId = id; }
    void setName(const string& n) { name = n; }

    void setPrice(double p) {
        if (p < 0) {
            throw invalid_argument("Price cannot be negative.");
        }
        price = p;
    }

    void setStockQuantity(int sq) {
        if (sq < 0) {
            throw invalid_argument("Stock quantity cannot be negative.");
        }
        stockQuantity = sq;
    }

    void display() const {
        cout << "Product ID: " << productId
                  << ", Name: " << name
                  << ", Price: $" << fixed << setprecision(2) << price
                  << ", Stock: " << stockQuantity << endl;
    }
};

class CartItem {
public:
    Product product;
    int quantity;

    CartItem(const Product& p, int qty) : product(p) {
        setQuantity(qty);
    }

    void setQuantity(int qty) {
        if (qty <= 0) {
            throw invalid_argument("Quantity must be positive.");
        }
        quantity = qty;
    }
};

class ShoppingCart {
public:
    vector<CartItem> items;

    void addItem(const Product& product, int qty) {
        if (qty <= 0) {
            throw invalid_argument("Quantity to add must be positive.");
        }
        if (product.getStockQuantity() < qty) {
            throw runtime_error("Not enough stock for " + product.getName());
        }

        for (auto& item : items) {
            if (item.product.getProductId() == product.getProductId()) {
                if (product.getStockQuantity() < (item.quantity + qty)) {
                    throw runtime_error("Adding " + to_string(qty) + " more units of " + product.getName() + " would exceed stock.");
                }
                item.quantity += qty;
                return;
            }
        }
        items.emplace_back(product, qty);
    }

    void removeItem(int productId) {
        items.erase(remove_if(items.begin(), items.end(),
                               [productId](const CartItem& item) { return item.product.getProductId() == productId; }),
                        items.end());
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.product.getPrice() * item.quantity;
        }
        return total;
    }

    void applyDiscount(double percentage) {
        if (percentage < 0 || percentage > 100) {
            throw invalid_argument("Discount percentage must be between 0 and 100.");
        }
        double discountFactor = 1.0 - (percentage / 100.0);
        for (auto& item : items) {
            item.product.setPrice(item.product.getPrice() * discountFactor);
        }
    }

    void displayCart() const {
        if (items.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "--- Shopping Cart Contents ---" << endl;
        for (const auto& item : items) {
            cout << "Product ID: " << item.product.getProductId()
                      << ", Name: " << item.product.getName()
                      << ", Price: $" << fixed << setprecision(2) << item.product.getPrice()
                      << ", Quantity: " << item.quantity
                      << ", Subtotal: $" << fixed << setprecision(2) << item.product.getPrice() * item.quantity << endl;
        }
        cout << "------------------------------" << endl;
        cout << "Total Cart Value: $" << fixed << setprecision(2) << calculateTotal() << endl;
    }

    void sortItemsByPriceDescending() {
        sort(items.begin(), items.end(),
             [](const CartItem& a, const CartItem& b) {
                 return (a.product.getPrice() * a.quantity) > (b.product.getPrice() * b.quantity);
             });
    }
};

int main() {
    vector<Product> availableProducts;
    try {
        availableProducts.emplace_back(1, "Laptop", 1200.00, 10);
        availableProducts.emplace_back(2, "Mouse", 25.50, 50);
        availableProducts.emplace_back(3, "Keyboard", 75.00, 20);
        availableProducts.emplace_back(4, "Monitor", 300.00, 5);
    } catch (const invalid_argument& e) {
        cerr << "Error creating product: " << e.what() << endl;
    }

    ShoppingCart myCart;

    // Adding items
    try {
        cout << "--- Adding Items to Cart ---" << endl;
        myCart.addItem(availableProducts[0], 1); // Laptop
        myCart.addItem(availableProducts[1], 2); // Mouse
        myCart.addItem(availableProducts[3], 1); // Monitor
        myCart.addItem(availableProducts[1], 3); // Add more mice
        myCart.displayCart();
    } catch (const exception& e) {
        cerr << "Error adding item to cart: " << e.what() << endl;
    }
    cout << endl;

    // Validate stock and input quantity (demonstrated by trying to add too many)
    try {
        cout << "--- Attempting to add more Monitors than stock ---" << endl;
        myCart.addItem(availableProducts[3], 5); // Monitor has 5 stock, already added 1, try to add 5 more
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << endl;


    // Removing item
    cout << "--- Removing Keyboard (ID 3) - not in cart, no effect ---" << endl;
    myCart.removeItem(3);
    myCart.displayCart();
    cout << endl;

    cout << "--- Removing Mouse (ID 2) ---" << endl;
    myCart.removeItem(2);
    myCart.displayCart();
    cout << endl;

    // Calculating total
    cout << "--- Current Total ---" << endl;
    cout << "Total: $" << fixed << setprecision(2) << myCart.calculateTotal() << endl;
    cout << endl;

    // Apply discount
    try {
        cout << "--- Applying 10% Discount ---" << endl;
        myCart.applyDiscount(10);
        myCart.displayCart();
    } catch (const invalid_argument& e) {
        cerr << "Error applying discount: " << e.what() << endl;
    }
    cout << endl;

    // Sorting and displaying
    cout << "--- Cart Items Sorted by Subtotal (Descending) ---" << endl;
    myCart.sortItemsByPriceDescending();
    myCart.displayCart();
    cout << endl;

    return 0;
}