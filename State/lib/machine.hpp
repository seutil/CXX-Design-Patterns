#pragma once
#include <memory>
#include <string>
#include "states/no-quater-state.hpp"
#include "states/has-quater-state.hpp"
#include "states/sold-out-state.hpp"
#include "states/sold-state.hpp"
#include "states/winner-state.hpp"

namespace MightyGumball {
#pragma region Machine
class Machine : public IState {
    friend class NoQuaterState;
    friend class HasQuaterState;
    friend class SoldOutState;
    friend class SoldState;
    friend class WinnerState;
public:
    friend std::ostream& operator<<(std::ostream& stream, const Machine& machine);
    enum class State {
        NO_QUATER,
        HAS_QUATER,
        SOLD_OUT,
        SOLD,
        WINNER
    };

    Machine(int gumballs_count);    
    void inject_quater() override;
    void eject_quater() override;
    void turn_crank() override;
    void dispense() override;
    void fill() override;
protected:
    void release_gumball();

    IState* _current_state;
    std::unique_ptr<NoQuaterState> _no_quater_state;
    std::unique_ptr<HasQuaterState> _has_quater_state;
    std::unique_ptr<SoldOutState> _sold_out_state;
    std::unique_ptr<SoldState> _sold_state;
    std::unique_ptr<WinnerState> _winner_state;
    int _gumballs_count;
};

std::ostream& operator<<(std::ostream& stream, const Machine& machine);
#pragma endregion

}
