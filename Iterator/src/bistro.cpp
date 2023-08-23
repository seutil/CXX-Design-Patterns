#include <iostream>
#include "waitress.hpp"

int main() {
    using namespace Bistro;

    std::unique_ptr breakfast_menu = std::make_unique<PancakeHouseMenu>();
    std::unique_ptr lunch_menu = std::make_unique<DinerMenu>();
    MenuItem vegetarian_food = MenuItem("Salad", "Salad with vegetables and fruits", true, 1.05);
    lunch_menu->add_menu_item(vegetarian_food);
    
    Waitress waitress(std::move(breakfast_menu), std::move(lunch_menu));
    waitress.print_menu();
    std::cout << "Is salad vegetarian food?: " << (waitress.is_vegeterian(vegetarian_food.name()) ? "Yes" : "No") << "\n";

    return 0;
}
