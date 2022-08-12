#include <iostream>
#include <vector>

using namespace std;

class FruitDrink {
    public:
        ~FruitDrink() {};
        virtual void juice() const = 0;
};

class OrangeJuice : public FruitDrink{
    public:
        OrangeJuice() {
            cout << "OJ obj inherit FruitDrink class\n";
        }

        void juice() const {
            cout << "I'm an orange juice\n";
        }
};

class BananaMilkShake : public FruitDrink{
    public:
        BananaMilkShake() {
            cout << "BMS obj inherit FruitDrink class\n";
        }

        void juice() const {
            cout << "I'm a banana milkshake\n";
        }
};

int main() {
    OrangeJuice objOJ;
    objOJ.juice();
    cout << "\n";
    BananaMilkShake objBMS;
    objBMS.juice();

    cout << "\nPointers from existing objects\n";
    std::vector<FruitDrink*> juices = {&objOJ, &objBMS};
    juices[0]->juice();
    juices[1]->juice();

    cout << "\nPointers from newly created objects\n";
    std::vector<FruitDrink*> pJuices = {new OrangeJuice, new BananaMilkShake};
    pJuices[0]->juice();
    pJuices[1]->juice();


    
}