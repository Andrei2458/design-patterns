#include <iostream>

using namespace std;

/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */

class Strategy {
    public:
        virtual ~Strategy() {}
        virtual void findRoute(string origin, string destination) const = 0;
};

/**
 * The Context defines the interface of interest to clients.
 */
class Context {
    /**
     * The Context maintains a reference to one of the Strategy objects.
     * The Context does not know the concrete class of a strategy. It
     * should work with all strategies via the Strategy interface.
     */
    private:
        Strategy* strategy_;

    public:
        Context(Strategy* strategy = nullptr) : strategy_(strategy) {

        }

        ~Context() {
            delete this->strategy_;
        }
        
        /**
        * Usually, the Context allows replacing a Strategy object at runtime.
        */
        void setStrategy(Strategy* strategy) {
            delete this->strategy_;
            this->strategy_ = strategy;    
        }

        /**
        * The Context delegates some work to the Strategy object instead of
        * implementing multiple versions of the algorithm on its own.
        */
        void showMeRoute(string source, string destination) {
            cout << "Context: Need to show an appropriate route. I don't knowhow to do it though\n";
            this->strategy_->findRoute(source, destination);
        }
};

/**
* Concrete Strategies implement the algorithm while following the base Strategy
* interface. The interface makes them interchangeable in the Context.
*/
class ConcreteStrategyCarRoute : public Strategy {
    public:
        void findRoute(string origin, string destination) const {
            cout << "Concrete Strategy: Map shows route for a car drive\n";
        }
};

class ConcreteStrategyBusRide : public Strategy {
    public:
        void findRoute(string origin, string destination) const {
            cout << "Concrete Strategy: Map shows route by bus ride\n";
        }
};

class ConcreteStrategyWalk : public Strategy {
    public: 
        void findRoute(string origin, string destination) const {
            cout << "Concrete Strategy: Map shows route by walk\n";
        }
};

int main() {
    // new also returns a pointer to the newly created object
    Context* context = new Context(new ConcreteStrategyCarRoute);
    cout << "Client is setting Strategy to Car Route\n";
    context->showMeRoute("home", "airport");

    cout << "\n";
    cout << "Client is setting Strategy to Bus Route\n";
    context->setStrategy(new ConcreteStrategyBusRide);
    context->showMeRoute("home", "airport");
    
    cout << "\n";
    cout << "Client is setting Strategy to walk\n";
    context->setStrategy(new ConcreteStrategyWalk);
    context->showMeRoute("home", "airport");

}




