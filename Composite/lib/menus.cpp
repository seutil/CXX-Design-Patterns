#include <iostream>
#include "menus.hpp"
using namespace Bistro;

#pragma region Menu Item
MenuItem::MenuItem(const std::string& name,
                   const std::string& descr,
                   bool vegeterian,
                   double cost)
    : _name{name},
      _description{descr},
      _vegeterian{vegeterian},
      _cost{cost}
{}

const std::string& MenuItem::name() const {
    return _name;
}

const std::string& MenuItem::description() const {
    return _description;
}

bool MenuItem::vegeterian() const {
    return _vegeterian;
}

double MenuItem::cost() const {
    return _cost;
}
#pragma endregion

#pragma region Iterators
PancakeHouseMenuIterator::PancakeHouseMenuIterator(std::vector<MenuItem>& menu_items)
    : _pos{0},
      _menu_items{menu_items}      
{}

bool PancakeHouseMenuIterator::has_next() const {
    return _pos < _menu_items.size();
}

MenuItem& PancakeHouseMenuIterator::next() {
    return _menu_items[_pos++];
}

DinerMenuIterator::DinerMenuIterator(std::list<MenuItem>& menu_items)
    : _pos{0},
      _menu_items{menu_items}
{}

bool DinerMenuIterator::has_next() const {
    return _pos < _menu_items.size();
}

MenuItem& DinerMenuIterator::next() {
    return *std::next(_menu_items.begin(), _pos++);
}
#pragma endregion

#pragma region Menus
PancakeHouseMenu::PancakeHouseMenu() {
    _menu_items.emplace_back("K&B's Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99);
    _menu_items.emplace_back("Regular Pancake Breakfast", "Pancakes with eggs and toast", true, 3.49);
    _menu_items.emplace_back("Bluebarry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
    _menu_items.emplace_back("Waffels", "Waffles, with your choice of blueberries or starberries", true, 3.49);
}

void PancakeHouseMenu::add(const MenuItem& menu_item) {
    _menu_items.push_back(menu_item);
}

std::shared_ptr<IIterator> PancakeHouseMenu::iterator() {
    return std::make_shared<PancakeHouseMenuIterator>(_menu_items);
}

DinerMenu::DinerMenu() {
    _menu_items.emplace_back("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", true, 2.99);
    _menu_items.emplace_back("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    _menu_items.emplace_back("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
    _menu_items.emplace_back("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05);
}

void DinerMenu::add(const MenuItem& menu_item) {
    if (_menu_items.size() >= MAX_MENU_ITEMS)
        std::cout << "Diner menu is full.\n";
    else
        _menu_items.push_back(menu_item);
}

std::shared_ptr<IIterator> DinerMenu::iterator() {
    return std::make_shared<DinerMenuIterator>(_menu_items);
}
#pragma endregion
