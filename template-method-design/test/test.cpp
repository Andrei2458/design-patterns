#include <iostream>
class TestClass {
    private:
        int input_;
    public: 
        TestClass(int input = 0) : input_(input) {
            std::cout << "input is: " << input << "\n";
            std::cout << "input_ is " << input_ << "\n";

        }
};

int main () {
    TestClass objTC(10);
}