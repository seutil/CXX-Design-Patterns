#include <iostream>
#include "waitress.hpp"
using namespace Bistro;

Waitress::Waitress(std::unique_ptr<PancakeHouseMenu>&& breakfast_menu,
                   std::unique_ptr<DinerMenu>&& lunch_menu)
    : m_breakfast_menu{std::move(breakfast_menu)},
      m_lunch_menu{std::move(lunch_menu)}
{}

void Waitress::print_menu() const {
    print_breakfast_menu();
    print_lunch_menu();
}

void Waitress::print_breakfast_menu() const {
    std::cout << "Breakfast Menu: \n";
    auto it = m_breakfast_menu->iterator();
    while (it->has_next()) {
        MenuItem& item = it->next();
        std::cout << item.name() << "\n";
    }
}

void Waitress::print_lunch_menu() const {
    std::cout << "\nLunch Menu: \n";
    auto it = m_lunch_menu->iterator();
    while (it->has_next()) {
        MenuItem& item = it->next();
        std::cout << item.name() << "\n";
    }
}

void Waitress::print_vegetarian_menu() const {
    std::cout << "Breakfast Vegetarian Menu:\n";
    auto itb  = m_breakfast_menu->iterator();
    while (itb->has_next()) {
        MenuItem& item = itb->next();
        if (item.vegeterian())
            std::cout << item.name() << "\n";
    }
    
    auto itl = m_lunch_menu->iterator();
    while (itl->has_next()) {
        MenuItem& item = itl->next();
        if (item.vegeterian())
            std::cout << item.name() << "\n";
    }
}

bool Waitress::is_vegeterian(const std::string& name) const {
    auto itb = m_breakfast_menu->iterator();
    while (itb->has_next()) {
        MenuItem& item = itb->next();
        if (item.vegeterian() && item.name() == name)
            return true;
    }

    auto itl = m_lunch_menu->iterator();
    while (itl->has_next()) {
        MenuItem& item = itl->next();
        if (item.vegeterian() && item.name() == name)
            return true;
    }

    return false;
}
