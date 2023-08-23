#include <iostream>
#include "waitress.hpp"
using namespace Bistro;

const size_t BREAKFAST_MENU_POS = 0;
const size_t LUNCH_MENU_POS = 1;

Waitress::Waitress(std::shared_ptr<PancakeHouseMenu> breakfast_menu,
                   std::shared_ptr<DinerMenu> lunch_menu)
{
    _menus[MenuPosition::BREAKFAST] = breakfast_menu;
    _menus[MenuPosition::LUNCH] = lunch_menu;
}

void Waitress::print_menu() const {
    std::cout << "=== ALL MENU ===\n";
    print_menu(MenuPosition::BREAKFAST);
    print_menu(MenuPosition::LUNCH);
}

void Waitress::print_breakfast_menu() const {
    std::cout << "=== BREAKFAST MENU ===\n";
    print_menu(MenuPosition::BREAKFAST);
}

void Waitress::print_lunch_menu() const {
    std::cout << "=== LUNCH MENU ===\n";
    print_menu(MenuPosition::LUNCH);
}

void Waitress::print_vegetarian_menu() const {
    std::cout << "=== VEGETARIAN MENU ===\n";
    print_menu(MenuPosition::BREAKFAST, true);
    print_menu(MenuPosition::LUNCH, true);
}

void Waitress::print_menu(MenuPosition pos,
                          bool vegeterian_only) const
{
    auto it = _menus.at(pos).lock()->iterator();
    while (it->has_next()) {
        MenuItem& menu_item = it->next();
        if (vegeterian_only && !menu_item.vegeterian())
            continue;

        std::cout << "* " << menu_item.name() << ": " << menu_item.cost() << "\n";  
    }
}
