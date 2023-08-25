#pragma once
#include "state.hpp"

namespace MightyGumball {
class Machine;

class SoldOutState : public IState {
public: 
    SoldOutState(Machine* machine);
    void inject_quater() override;
    void eject_quater() override;
    void turn_crank() override;
    void dispense() override;
    void fill() override;
protected:
    Machine* _machine;
};
}
