#include <iostream>
#include "../machine.hpp"
#include "no-quater-state.hpp"
using namespace MightyGumball;


NoQuaterState::NoQuaterState(Machine* machine)
    : _machine{machine}
{}

void NoQuaterState::inject_quater() {
    std::cout << "Quater injected\n";
    _machine->_current_state = _machine->_has_quater_state.get();
}

void NoQuaterState::eject_quater() {
    std::cout << "You haven't injected a quater\n";
}

void NoQuaterState::turn_crank() {
    std::cout << "You turned but there's no quater\n";
}

void NoQuaterState::dispense() {
    std::cout << "You need to pay first\n";
}