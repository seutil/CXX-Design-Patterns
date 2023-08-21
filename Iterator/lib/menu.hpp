#pragma once
#include <memory>
#include <string>
#include <list>
#include <vector>

namespace Bistro
{


#pragma region Menu
class MenuItem
{
public:
    MenuItem(const std::string& name,
             const std::string& description,
             bool vegeterian,
             double price);
    const std::string& name() const;
    const std::string& description() const;
    bool vegeterian() const;
    double price() const;
protected:
    std::string m_name;
    std::string m_description;
    bool m_vegetarian;
    double m_price;
};
#pragma endregion

#pragma region Iterators
class IIterator
{
public:
    virtual bool has_next() const = 0;
    virtual MenuItem& next() = 0;
    virtual ~IIterator() = default;
};

class PancakeHouseMenuIterator : public IIterator
{
public:
    PancakeHouseMenuIterator(std::list<MenuItem>& list);
    bool has_next() const override;
    MenuItem& next() override;
protected:
    ulong m_pos;
    std::list<MenuItem>& m_list;
};

class DinerMenuIterator : public IIterator
{
public:
    DinerMenuIterator(std::vector<MenuItem>& vector);
    bool has_next() const override;
    MenuItem& next() override;
protected:
    ulong m_pos;
    std::vector<MenuItem>& m_vector;
};
#pragma endregion

#pragma region Menus
class IMenu
{
public:
    virtual std::unique_ptr<IIterator> iterator() = 0;
    virtual ~IMenu() = default;
};

class PancakeHouseMenu : public IMenu
{
public: 
    PancakeHouseMenu();
    void add_menu_item(const MenuItem& menu_item);
    const std::list<MenuItem>& menu_items() const;
    std::unique_ptr<IIterator> iterator() override;
protected:
    std::list<MenuItem> m_menu_items;
};

class DinerMenu : public IMenu
{
public:
    DinerMenu();
    void add_menu_item(const MenuItem& menu_item);
    const std::vector<MenuItem>& menu_items() const;
    std::unique_ptr<IIterator> iterator() override;
protected:
    std::vector<MenuItem> m_menu_items;
};
#pragma endregion

}
