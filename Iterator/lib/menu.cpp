#include <iostream>
#include "menu.hpp"
using namespace Bistro;

const size_t DINER_MENU_MAX_ITEMS = 6;

#pragma region Menu
MenuItem::MenuItem(const std::string& name,
                   const std::string& description,
                   bool vegeterian,
                   double price)
    : m_name{name},
      m_description{description},
      m_vegetarian{vegeterian},
      m_price{price}
{}

const std::string& MenuItem::name() const {
    return m_name;
}

const std::string& MenuItem::description() const {
    return m_description;
}

bool MenuItem::vegeterian() const {
    return m_vegetarian;
}

double MenuItem::price() const {
    return m_price;
}
#pragma endregion

#pragma region Iterators
PancakeHouseMenuIterator::PancakeHouseMenuIterator(std::list<MenuItem>& list)
    : m_list{list},
      m_pos{0}
{}

bool PancakeHouseMenuIterator::has_next() const {
    return m_pos < m_list.size();
}

MenuItem& PancakeHouseMenuIterator::next() {
    auto it = m_list.begin();
    std::advance(it, m_pos++);
    return *it;
}

DinerMenuIterator::DinerMenuIterator(std::vector<MenuItem>& vector)
    : m_vector{vector},
      m_pos{0}
{}

bool DinerMenuIterator::has_next() const {
    return m_pos < m_vector.size();
}

MenuItem& DinerMenuIterator::next() {
    return m_vector[m_pos++];
}
#pragma endregion

#pragma region Menus
PancakeHouseMenu::PancakeHouseMenu() {
    m_menu_items.emplace_back("K&B's Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99);
    m_menu_items.emplace_back("Regular Pancake Breakfast", "Pancakes with eggs and toast", true, 3.49);
    m_menu_items.emplace_back("Bluebarry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
    m_menu_items.emplace_back("Waffels", "Waffles, with your choice of blueberries or starberries", true, 3.49);
}

void PancakeHouseMenu::add_menu_item(const MenuItem& menu_item) {
    m_menu_items.push_back(menu_item);
}

const std::list<MenuItem>& PancakeHouseMenu::menu_items() const {
    return m_menu_items;
}

std::unique_ptr<IIterator> PancakeHouseMenu::iterator() {
    return std::make_unique<PancakeHouseMenuIterator>(m_menu_items);
}

DinerMenu::DinerMenu() {
    m_menu_items.emplace_back("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", true, 2.99);
    m_menu_items.emplace_back("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    m_menu_items.emplace_back("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
    m_menu_items.emplace_back("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05);
}

void DinerMenu::add_menu_item(const MenuItem& menu_item) {
    if (m_menu_items.size() >= DINER_MENU_MAX_ITEMS) {
        std::cout << "Sorry, menu is full! Can't add new item to menu\n";
        return;
    }

    m_menu_items.push_back(menu_item);
}

const std::vector<MenuItem>& DinerMenu::menu_items() const {
    return m_menu_items;
}

std::unique_ptr<IIterator> DinerMenu::iterator() {
    return std::make_unique<DinerMenuIterator>(m_menu_items);
}
#pragma endregion
