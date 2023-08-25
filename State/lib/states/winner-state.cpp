#include <iostream>
#include "../machine.hpp"
#include "winner-state.hpp"
using namespace MightyGumball;

WinnerState::WinnerState(Machine* machine)
    : _machine{machine}
{}

void WinnerState::inject_quater() {
    std::cout << "Please wait, we already giving you a gumball\n";
}

void WinnerState::eject_quater() {
    std::cout << "Sorry, you already turned the crank\n";
}

void WinnerState::turn_crank() {
    std::cout << "Turning twice doesn't get you another gumball!\n";
}

void WinnerState::dispense() {
    _machine->release_gumball();
    if (_machine->_gumballs_count <= 0)
        return;

    std::cout << "YOU'R WINNER! You got two gumballs for your quater\n";
    _machine->release_gumball();
}
