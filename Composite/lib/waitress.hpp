#pragma once
#include <unordered_map>
#include "menus.hpp"

namespace Bistro {
class Waitress {
public:
    Waitress(std::shared_ptr<PancakeHouseMenu> pancake_house_menu,
             std::shared_ptr<DinerMenu> diner_menu);
    void print_menu() const;
    void print_breakfast_menu() const;
    void print_lunch_menu() const;
    void print_vegetarian_menu() const;
protected:
    enum class MenuPosition {
        BREAKFAST = 0,
        LUNCH
    };

    void print_menu(MenuPosition pos,
                    bool vegeterian_only = false) const;
    std::unordered_map<MenuPosition, std::weak_ptr<IMenu>> _menus;
};
}