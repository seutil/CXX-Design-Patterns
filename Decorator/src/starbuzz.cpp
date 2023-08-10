#include <iostream>
#include <beverages.hpp>
#include <beverage-condiments.hpp>

int main()
{
    using namespace Starbuzz;

    std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>(Espresso::Size::GRANDE);
    beverage = std::make_shared<Mocha>(beverage);
    beverage = std::make_shared<Mocha>(beverage);
    beverage = std::make_shared<Whip>(beverage);
    std::cout << "You'r order: " << beverage->name() << "\n"
              << "Order cost:  " << beverage->cost() << "\n";
    return 0;
}
