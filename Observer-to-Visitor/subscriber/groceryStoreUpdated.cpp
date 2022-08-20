#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// makes sense to declare this as a private class member?
map<string, bool> groceryItems {};

class GroceryStore {
    public: 
        GroceryStore(map<string, bool> const& grocery) {
            groceryItems = grocery;
        }

        void refillInventory(string itemName) {
            auto itemToRefill = groceryItems.find(itemName);
            itemToRefill->second = true;
            cout << "Item " << itemName << " has been refilled in the Grocery Store\n"; 
        }
        
};

class Customer {
    public:
        bool purchaseItem (string itemName) {
            auto itemToBuy = groceryItems.find(itemName);
            if (itemToBuy != end(groceryItems) && itemToBuy->second) {
                cout << "Item " << itemName << " is available\n";
                return true;
            } else {
                cout << "Item " << itemName << " is not available\n";
                return false;
            }
            
            
        }
};



int main() {
    map<string, bool> itemList {
        {"Flour", true},
        {"Rice", true},
        {"Brown Bread", false},
        {"Blueberry Syrup", false},
        {"Detergent", true}
    };

    GroceryStore objGs(itemList);
    Customer objCust;

    objCust.purchaseItem("Detergent");
    objCust.purchaseItem("Flour");
    objCust.purchaseItem("Rice");
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");

    cout << "\n";
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");

    cout << "\n";
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");

    cout << "\n";
    objGs.refillInventory("Brown Bread");
    objGs.refillInventory("Blueberry Syrup");

    cout << "\n";
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
    return 0;
}