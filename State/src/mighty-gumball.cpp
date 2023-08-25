#include <iostream>
#include <machine.hpp>

int main() {
    using namespace MightyGumball;

    Machine machine(5);
    
    machine.inject_quater();
    machine.turn_crank();
    std::cout << machine;
    std::cout << "======================\n\n";

    machine.inject_quater();
    machine.eject_quater();
    machine.turn_crank();
    std::cout << machine;
    std::cout << "======================\n\n";

    machine.inject_quater();
    machine.turn_crank();
    machine.inject_quater();
    machine.turn_crank();
    machine.eject_quater();
    std::cout << machine;
    std::cout << "======================\n\n";

    machine.inject_quater();
    machine.inject_quater();
    machine.turn_crank();
    machine.inject_quater();
    machine.turn_crank();
    machine.inject_quater();
    machine.turn_crank();
    std::cout << machine;
    std::cout << "======================\n\n";

    machine.fill();
    std::cout << machine;
    std::cout << "======================\n\n";

    return 0;
}
