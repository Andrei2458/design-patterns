#include <iostream>

using namespace std;

/**
 * This is an abstract class that defines the skeleton
 * of the algorithms that the concrete classes can inherit
 */

class FruitDrink {
    public:
        // Template function
        void prepareFruitDrink() {
            peel();
            cutInPieces();
            addToMixerGrinder();
            addCondiments();
            startMixerGrinder();
            stopMixerGrinder();
        }

        virtual ~FruitDrink() {}
    
    protected:
        // Compulsory functions -> since they are pure virtual functions " = 0"
        virtual void peel() const = 0;
        virtual void cutInPieces() const = 0;
        virtual void addToMixerGrinder() const = 0;
        virtual void startMixerGrinder() const = 0;
        virtual void stopMixerGrinder() const = 0;

        // Optional hook function -> since this is just a virtual functions. missing " = 0"
        virtual void addCondiments() const {};
};

/**
 * Concrete classes inheriting abstract class FruitDrink
 * They will implement all the compulsory functions (pure virtual)
 * it is their choice to implement/or not the optional hook functions
 */

class OrangeJuice : public FruitDrink {
    protected:
        void peel() const {
            cout << "Peeling orange\n";
        }

        void cutInPieces() const {
            cout << "Cutting orange into pieces\n";
        }

        void addToMixerGrinder() const {
            cout << "Adding orange pieces to mixer grinder\n";
        } 

        void startMixerGrinder() const {
            cout << "Start Mixer Grinder\n";
        }

        void stopMixerGrinder() const {
            cout << "Stop Mixer Grinder\n";
        }
};

class BananaMilkShake : public FruitDrink{
    protected:
        void peel() const {
            cout << "Peeling banana\n";
        }

        void cutInPieces() const {
            cout << "Cutting banana into pieces\n";
        }

        void addToMixerGrinder() const {
            cout << "Adding banana pieces to mixer grinder\n";
        }

        void addCondiments() const {
            cout << "Adding Milk and Sugar\n";
        }
        void startMixerGrinder() const {
            cout << "Start Mixer Grinder\n";
        }
        
        void stopMixerGrinder() const {
            cout << "Stop Mixer Grinder\n";
        }

};

int main() {
    OrangeJuice objOJ;
    objOJ.prepareFruitDrink();
    cout << "\n";
    BananaMilkShake objBMS;
    objBMS.prepareFruitDrink();
}
