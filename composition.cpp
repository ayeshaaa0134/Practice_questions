#include <iostream>
using namespace std;

class Engine {
    public:
        void start() { std::cout << "Engine started!\n"; }
    };
    
    class Car {
    private:
        std::unique_ptr<Engine> engine; // Composition (exclusive ownership)
    public:
        Car() : engine(std::make_unique<Engine>()) {}
        void startCar() { engine->start(); }
        // ~Car() auto-deletes engine (no manual delete needed)
    };