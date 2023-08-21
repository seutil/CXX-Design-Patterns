#pragma once
#include <memory>
#include <string>
#include <vector>
#include "menu.hpp"

namespace Bistro
{

class Waitress
{
public:
    Waitress(std::unique_ptr<PancakeHouseMenu>&& breakfast_menu,
             std::unique_ptr<DinerMenu>&& lunch_menu);
    void print_menu() const;
    void print_breakfast_menu() const;
    void print_lunch_menu() const;
    void print_vegetarian_menu() const;
    bool is_vegeterian(const std::string& name) const;
protected:
    std::unique_ptr<IMenu> m_breakfast_menu;
    std::unique_ptr<IMenu> m_lunch_menu;
};

}
