#include <unordered_map>
#include "pizza.hpp"
using namespace Pizzeria;

const std::unordered_map<Pizza::Size, double> PIZZA_SIZE_MULTIPLIER =
{
    { Pizza::Size::SMALL,  1    },
    { Pizza::Size::MEDIUM, 1.25 },
    { Pizza::Size::LARGE,  1.50 }
};


Pizza::Pizza(const std::string& name,
             const double& cost,
             const Size& size)
    : m_name{name},
      m_cost{cost},
      m_size{size}
{}

const std::string&
Pizza::name() const
{
    return m_name;
}

double
Pizza::cost() const
{
    return m_cost * PIZZA_SIZE_MULTIPLIER.at(m_size);
}

const Pizza::Size&
Pizza::size() const
{
    return m_size;
}

void
Pizza::set_size(const Size& new_size)
{
    m_size = new_size;
}

CheesePizza::CheesePizza(const Size& size)
    : Pizza("Cheese Pizza", 17, size)
{}

PepperoniPizza::PepperoniPizza(const Size& size)
    : Pizza("Pepperoni Pizza", 17, size)
{}

ClamPizza::ClamPizza(const Size& size)
    : Pizza("Clam Pizza", 17, size)
{}

VeggiePizza::VeggiePizza(const Size& size)
    : Pizza("Veggie Pizza", 15, size)
{}

PizzaStyle::PizzaStyle(std::shared_ptr<Pizza> pizza,
                       const std::string& name)
    : Pizza(pizza->m_name + ", " + name, pizza->m_cost, pizza->m_size),
      m_pizza{pizza}
{}

NewYorkPizzaStyle::NewYorkPizzaStyle(std::shared_ptr<Pizza> pizza)
    : PizzaStyle(pizza, "New York Style")
{}

ChicagoPizzaStyle::ChicagoPizzaStyle(std::shared_ptr<Pizza> pizza)
    : PizzaStyle(pizza, "Chicago Style")
{}

CaliforniaPizzaStyle::CaliforniaPizzaStyle(std::shared_ptr<Pizza> pizza)
    : PizzaStyle(pizza, "California Style")
{}
