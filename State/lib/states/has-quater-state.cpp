#include <iostream>
#include "../machine.hpp"
#include "has-quater-state.hpp"
using namespace MightyGumball;

HasQuaterState::HasQuaterState(Machine* machine)
    : _machine{machine}
{}

void HasQuaterState::inject_quater() {
    std::cout << "You can't insert another quater\n";
}

void HasQuaterState::eject_quater() {
    std::cout << "Eject your's quater\n";
    _machine->_current_state = _machine->_no_quater_state.get();
}

void HasQuaterState::turn_crank() {
    std::cout << "You turned\n";
    if (std::rand() % 11 <= 1)
        _machine->_current_state = _machine->_winner_state.get();
    else
        _machine->_current_state = _machine->_sold_state.get();

    _machine->_current_state->dispense();
}

void HasQuaterState::dispense() {
    std::cout << "No gumbal dispensed\n";
}