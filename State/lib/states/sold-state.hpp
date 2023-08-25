#pragma once
#include "state.hpp"

namespace MightyGumball {
class Machine;

class SoldState : public IState {
public:
    SoldState(Machine* machine);
    void inject_quater() override;
    void eject_quater() override;
    void turn_crank() override;
    void dispense() override;
protected:
    Machine* _machine;
};
}