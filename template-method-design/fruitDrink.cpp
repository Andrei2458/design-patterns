#include <iostream>

using namespace std;

class OrangeJuice {
    public:
        void prepareOrangeJuice() {
            peelOrange();
            cutInPieces();
            addToMixerGrinder();
            startMixerGrinder();
            stopMixerGrinder();
        }

        void peelOrange() {
            cout << "Peeling orange\n";
        }

        void cutInPieces() {
            cout << "Cutting orange into pieces\n";
        }

        void addToMixerGrinder() {
            cout << "Adding orange pieces to mixer grinder\n";
        }

        void startMixerGrinder() {
            cout << "Start Mixer Grinder\n";
        }
        
        void stopMixerGrinder() {
            cout << "Stop Mixer Grinder\n";
        }
};

class BananaMilkShake {
    public:
        void prepareBananaMilkShake() {
            peelBanana();
            cutInPieces();
            addToMixerGrinder();
            addMilkAndSugar();
            startMixerGrinder();
            stopMixerGrinder();
        }

        void peelBanana() {
            cout << "Peeling banana\n";
        }

        void cutInPieces() {
            cout << "Cutting banana into pieces\n";
        }

        void addToMixerGrinder() {
            cout << "Adding banana pieces to mixer grinder\n";
        }

        void addMilkAndSugar() {
            cout << "Adding Milk and Sugar\n";
        }
        void startMixerGrinder() {
            cout << "Start Mixer Grinder\n";
        }
        
        void stopMixerGrinder() {
            cout << "Stop Mixer Grinder\n";
        }        
};

int main() {
    OrangeJuice objOJ;
    BananaMilkShake objBMS;

    objOJ.prepareOrangeJuice();
    cout << "\n";
    objBMS.prepareBananaMilkShake();

    return 0;
}