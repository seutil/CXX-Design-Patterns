#include <iostream>
#include <menus.hpp>
#include <waitress.hpp>

int main() {
    using namespace Bistro;

    std::shared_ptr breakfast_menu = std::make_shared<PancakeHouseMenu>();
    std::shared_ptr lunch_menu = std::make_shared<DinerMenu>();
    Waitress waitress(breakfast_menu, lunch_menu);

    waitress.print_menu();
    std::cout << "\n";
    waitress.print_vegetarian_menu();

    return 0;
}
