#include <components.hpp>

int main() {
    using namespace HomeCinema;
    std::unique_ptr home_cinema = std::make_unique<CinemaFacade>();
    home_cinema->on();
    home_cinema->off();
    return 0;
}
