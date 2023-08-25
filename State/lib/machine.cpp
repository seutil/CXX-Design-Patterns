#include <iostream>
#include "machine.hpp"
using namespace MightyGumball;

Machine::Machine(int gumballs_count)
    : _no_quater_state{std::make_unique<NoQuaterState>(this)},
      _has_quater_state{std::make_unique<HasQuaterState>(this)},
      _sold_out_state{std::make_unique<SoldOutState>(this)},
      _sold_state{std::make_unique<SoldState>(this)},
      _winner_state{std::make_unique<WinnerState>(this)},
      _gumballs_count{gumballs_count}
{
    if (_gumballs_count > 0)
        _current_state = _no_quater_state.get();
    else
        _current_state = _sold_out_state.get();
}

void Machine::inject_quater() {
    _current_state->inject_quater();
}

void Machine::eject_quater() {
    _current_state->eject_quater();
}

void Machine::turn_crank() {
    _current_state->turn_crank();
}

void Machine::dispense() {
    _current_state->dispense();
}

void Machine::fill() {
    _current_state->fill();
}

void Machine::release_gumball() {
    std::cout << "A gumball comes rolling out the slot...\n";
    if (_gumballs_count <= 0) {
        std::cout << "Sorry, gumbell machine is sold out\n";
        _current_state = _sold_out_state.get();
        return;
    }

    --_gumballs_count;
    _current_state = _no_quater_state.get();
}

std::ostream& MightyGumball::operator<<(std::ostream& stream, const Machine& machine) {
    std::string state;
    if (machine._current_state == machine._has_quater_state.get())
        state = "Has Quater";
    else if (machine._current_state == machine._no_quater_state.get())
        state = "No Quater";
    else if (machine._current_state == machine._sold_out_state.get())
        state = "Sold Out";
    else if (machine._current_state == machine._sold_state.get())
        state = "Sold";

    stream << "Gumball Machine State: " << state << "\n";
    return stream;
}
#pragma endregion