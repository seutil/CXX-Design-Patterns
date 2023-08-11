#include <stdexcept>
#include "pizza-store.hpp"
using namespace Pizzeria;

std::shared_ptr<Pizza>
PizzaStore::order_pizza(const std::string& type) const
{
    std::shared_ptr<Pizza> pizza;
    if (type == "cheese")
        pizza = std::make_shared<CheesePizza>();
    else if (type == "pepperoni")
        pizza = std::make_shared<PepperoniPizza>();
    else if (type == "clam")
        pizza = std::make_shared<ClamPizza>();
    else if (type == "veggie")
        pizza = std::make_shared<VeggiePizza>();
    else
        throw std::logic_error("Unknown pizza type");
    
    decorate_pizza(pizza);
    return pizza;
}

void
NewYorkPizzaStore::decorate_pizza(std::shared_ptr<Pizza>& pizza) const
{
    pizza = std::make_shared<NewYorkPizzaStyle>(pizza);
}

void
ChicagoPizzaStore::decorate_pizza(std::shared_ptr<Pizza>& pizza) const
{
    pizza = std::make_shared<ChicagoPizzaStyle>(pizza);
}

void
CaliforniaPizzaStore::decorate_pizza(std::shared_ptr<Pizza>& pizza) const
{
    pizza = std::make_shared<CaliforniaPizzaStyle>(pizza);
}
