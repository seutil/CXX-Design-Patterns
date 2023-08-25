#include <iostream>
#include "../machine.hpp"
#include "sold-state.hpp"
using namespace MightyGumball;

SoldState::SoldState(Machine* machine)
    : _machine{machine}
{}

void SoldState::inject_quater() {
    std::cout << "Please wait, we already giving you a gumball\n";
}

void SoldState::eject_quater() {
    std::cout << "Sorry, you already turned the crank\n";
}

void SoldState::turn_crank() {
    std::cout << "Turning twice doesn't get you another gumball!\n";
}

void SoldState::dispense() {
    _machine->release_gumball();
}
