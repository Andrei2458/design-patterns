#include <iostream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

int const total_grocery_items = 5;

// makes sense to declare this as a private class member?
map<string, bool> groceryItems {};

class Observer {
    public:
        virtual ~Observer() {};
        virtual void update(string const& message_from_subject) const = 0;
};

class Subject {
    public:
        virtual ~Subject() {};
        virtual void subscribe(Observer* observer) = 0;
        virtual void unsubscribe(Observer* observer) = 0;
        virtual void notify(string msg) = 0;
};

class GroceryStore : public Subject {
    public: 
        GroceryStore(map<string, bool> const& grocery) {
            groceryItems = grocery;
        }

        virtual ~GroceryStore() {
            cout << "Goodbye, I was the Subject!\n";
        }

        void subscribe(Observer* observer) {
            cout << "An observer has subscribed!\n";
            list_observer.push_back(observer);
        }

        void unsubscribe(Observer* observer) {
            cout << "A customer has unsubscribed!\n";
            list_observer.remove(observer);
        }

        void notify(string msg) {
            auto iterator = begin(list_observer);
            while (iterator != end(list_observer)) {
                (*iterator)->update(msg);
                iterator++;
            } 
        }

        void refillInventory(string itemName) {
            auto itemToRefill = groceryItems.find(itemName);
            itemToRefill->second = true;
            cout << "Refilling the stock for item " << itemName << "\n";
            notify("Item " + itemName + " has been refilled in the Grocery Store");
        }

    private:
        list<Observer*> list_observer;
};

class Customer : public Observer {
    public: 
        Customer(GroceryStore& subject) : subject_(subject) {
            this->subject_.subscribe(this);
        }
        virtual ~Customer() {
            cout << "Goodbye, I was the observer/n";
        }
        void update(string const& msg) const{
            cout << "Hey customer! A new message is available --> " << msg << "\n";
        }

        void unsubscribeCustomer() {
            cout << "Customer wants to unsubscribe the Grocery Store notifications - ";
            subject_.unsubscribe(this);
        }

        bool purchaseItem(string const& itemName) {
            cout << "Customer wants to purchase item " << itemName << "\n";
            auto itemToBuy = groceryItems.find(itemName);
            if (itemToBuy != end(groceryItems)) {
                cout << "Item " << itemName << " is available\n";
                return true;
            } else {
                cout << "The item " << itemName << " is not available in the Grocery Store\n";
                return false;
            }
            
        }

    private:
        GroceryStore& subject_;
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
    Customer objCust(objGs);

    objCust.purchaseItem("Detergent");
    objCust.purchaseItem("Flour");
    objCust.purchaseItem("Rice");
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
    cout << "\n";
    objGs.refillInventory("Brown Bread");
    objCust.purchaseItem("Brown Bread");
    objCust.unsubscribeCustomer();
    cout << "\n";
    objGs.refillInventory("Blueberry Syrup");

    return 0;
}

