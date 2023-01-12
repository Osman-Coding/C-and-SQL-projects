#include <iostream>
#include <map>
using namespace std;  

int main() {
    // Create a map to store the prices of items
    map<string, double> prices;
    prices["apple"] = 0.50;
    prices["banana"] = 0.25;
    prices["orange"] = 0.75;
    prices["watermelon"] = 2.50;

    // Create a map to store the quantity of items in the cart
    map<string, int> cart;
    cart["apple"] = 2;
    cart["banana"] = 5;
    cart["orange"] = 3;
    cart["watermelon"] = 1;

    // Initialize the total cost to 0
    double totalCost = 0;

    // Iterate through the cart and calculate the total cost
    for (auto const& [item, quantity] : cart) {
        double itemCost = prices[item] * quantity;
        totalCost += itemCost;
    }

    // Print the total cost
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}
