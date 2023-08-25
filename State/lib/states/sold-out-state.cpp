#include <iostream>
#include "../machine.hpp"
#include "sold-out-state.hpp"
using namespace MightyGumball;

SoldOutState::SoldOutState(Machine* machine)
    : _machine{machine}
{}

void SoldOutState::inject_quater() {
    std::cout << "You can't inject a quater, machine is sold out\n";
}

void SoldOutState::eject_quater() {
    std::cout << "You can't eject, you haven't inject a quater yet\n";
}

void SoldOutState::turn_crank() {
    std::cout << "You turned, but there no gumballs\n";
}

void SoldOutState::dispense() {
    std::cout << "No gumball disponsed\n";
}

void SoldOutState::fill() {
    std::cout << "Add 5 gumballs to the machine\n";
    _machine->_current_state = _machine->_no_quater_state.get();
}
