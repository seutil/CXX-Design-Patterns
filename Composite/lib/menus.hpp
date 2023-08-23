#pragma once
#include <memory>
#include <list>
#include <vector>
#include <iostream>

namespace Bistro {
#pragma region Menu Item
class MenuItem {
public:
    MenuItem(const std::string& name,
             const std::string& description,
             bool vegeterian,
             double cost);
    const std::string& name() const;
    const std::string& description() const;
    bool vegeterian() const;
    double cost() const;
protected:
    std::string _name;
    std::string _description;
    bool _vegeterian;
    double _cost;
};
#pragma endregion

#pragma region Iterators
class IIterator {
public:
    virtual bool has_next() const = 0;
    virtual MenuItem& next() = 0;
    virtual ~IIterator() = default;
};

class PancakeHouseMenuIterator : public IIterator {
public:
    PancakeHouseMenuIterator(std::vector<MenuItem>& menu_items);
    bool has_next() const override;
    MenuItem& next() override;
protected:
    size_t _pos;
    std::vector<MenuItem>& _menu_items;
};

class DinerMenuIterator : public IIterator {
public:
    DinerMenuIterator(std::list<MenuItem>& menu_items);
    bool has_next() const override;
    MenuItem& next() override;
protected:
    size_t _pos;
    std::list<MenuItem>& _menu_items;
};
#pragma endregion

#pragma region Menus
class IMenu {
public:
    virtual void add(const MenuItem& menu_item) = 0;
    virtual std::shared_ptr<IIterator> iterator() = 0;
    virtual ~IMenu() = default;
};

class PancakeHouseMenu : public IMenu {
public:
    PancakeHouseMenu();
    void add(const MenuItem& menu_item);
    std::shared_ptr<IIterator> iterator() override;
protected:
    std::vector<MenuItem> _menu_items;
};

class DinerMenu : public IMenu {
public:
    DinerMenu();
    void add(const MenuItem& menu_item);
    std::shared_ptr<IIterator> iterator() override;
protected:
    static const size_t MAX_MENU_ITEMS = 6;
    std::list<MenuItem> _menu_items;
};
#pragma endregion
}