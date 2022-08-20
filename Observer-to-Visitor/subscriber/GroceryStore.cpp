#include <iostream>

using namespace std;

#define TOTAL_GROCERY_ITEMS 5

struct GroceryItem {
    string itemName;
    bool available;
};

GroceryItem groceryItems[TOTAL_GROCERY_ITEMS];


class GroceryStore{
    public:
        GroceryStore(GroceryItem* grocery) {
            for (int i = 0; i < TOTAL_GROCERY_ITEMS; i++) {
                groceryItems[i].itemName = grocery[i].itemName;
                groceryItems[i].available = grocery[i].available;
            }
        }
    
    void refillInventory(string itemName){
        for (int i = 0; i < TOTAL_GROCERY_ITEMS; i++) {
            if (itemName == groceryItems[i].itemName) {
                groceryItems[i].available = true;
                cout << "Item " << itemName << "has been refilled in the Grocery Store\n";
            }
        }
    }
};

class Customer {
    public: 
        bool purchaseItem(string itemName) {
            for (int i = 0; i < TOTAL_GROCERY_ITEMS;  i++) {
                if (itemName == groceryItems[i].itemName && groceryItems[i].available) {
                    cout << "Item " << itemName << " is available\n";
                    return true;
                }
            }
            cout << "Item " << itemName << " is not available\n";
            return false;
        }
};

int main(void) {
    GroceryItem itemList[] = {
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




