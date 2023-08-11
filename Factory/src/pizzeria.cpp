#include <iostream>
#include <algorithm>
#include <pizza-store.hpp>


int main()
{
    using namespace Pizzeria;

    std::unique_ptr<PizzaStore> pizza_store = std::make_unique<NewYorkPizzaStore>();
    std::string pizza_type;
    std::cout << "Enter pizza type: ";
    std::cin >> pizza_type;
    std::transform(pizza_type.begin(), pizza_type.end(), pizza_type.begin(), [](char c) { return std::tolower(c); });

    std::shared_ptr<Pizza> pizza;
    try
    {
        pizza = pizza_store->order_pizza(pizza_type);
    }
    catch (std::logic_error ex)
    {
        std::cout << "Unknown pizza type\n";
        return 1;
    }
    std::cout << "Pizza: " << pizza->name() << "\n"
              << "Cost: " << pizza->cost() << "\n";
    return 0;
}
