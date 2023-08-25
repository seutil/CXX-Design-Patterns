#pragma once

namespace MightyGumball {
class IState {
public:
    virtual void inject_quater() = 0;
    virtual void eject_quater() = 0;
    virtual void turn_crank() = 0;
    virtual void dispense() = 0;
    virtual void fill();
    virtual ~IState() = default;
};
}
