#pragma once
#include <string>

namespace Pizzeria
{

class Pizza
{
public:
    enum class Size
    {
        SMALL,
        MEDIUM,
        LARGE
    };

    const std::string& name() const;
    const double& cost() const;
    const Size& size() const;
    void set_size(const Size& new_size);
    virtual ~Pizza() = default;
protected:
    Pizza(const std::string& name,
          const double& cost,
          const Size& size);

    std::string m_name;
    double m_cost;
    Size m_size;
};

class CheesePizza : public Pizza
{
public:
    CheesePizza(const Size& size = Size::MEDIUM);
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza(const Size& size = Size::MEDIUM);
};

class ClamPizza : public Pizza
{
public:
    ClamPizza(const Size& size = Size::MEDIUM);
};

class VeggiePizza : public Pizza
{
public:
    VeggiePizza(const Size& size = Size::MEDIUM);
};

}
