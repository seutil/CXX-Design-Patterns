#include "beverage-condiments.hpp"
using namespace Starbuzz;

BeverageCondiment::BeverageCondiment(std::shared_ptr<Beverage> beverage,
                                     const std::string& name,
                                     const double& cost)
    : Beverage(beverage->name() + ", " + name, beverage->cost() + cost, beverage->size()),
      m_beverage{beverage}
{}

Milk::Milk(std::shared_ptr<Beverage> beverage)
    : BeverageCondiment(beverage, "Milk", .10)
{}

Mocha::Mocha(std::shared_ptr<Beverage> beverage)
    : BeverageCondiment(beverage, "Mocha", .20)
{}

Soy::Soy(std::shared_ptr<Beverage> beverage)
    : BeverageCondiment(beverage, "Soy", .15)
{}

Whip::Whip(std::shared_ptr<Beverage> beverage)
    : BeverageCondiment(beverage, "Whip", .10)
{}
