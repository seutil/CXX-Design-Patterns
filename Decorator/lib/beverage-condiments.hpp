#pragma once
#include <memory>
#include "beverages.hpp"

namespace Starbuzz
{
class BeverageCondiment : public Beverage {
protected:
    BeverageCondiment(std::shared_ptr<Beverage> beverage,
                      const std::string& name,
                      const double& cost);

    std::weak_ptr<Beverage> m_beverage;
};

class Milk : public BeverageCondiment {
public:
    Milk(std::shared_ptr<Beverage> beverage);
};

class Mocha : public BeverageCondiment {
public:
    Mocha(std::shared_ptr<Beverage> beverage);
};

class Soy : public BeverageCondiment {
public:
    Soy(std::shared_ptr<Beverage> beverage);
};

class Whip : public BeverageCondiment {
public:
    Whip(std::shared_ptr<Beverage> beverage);
};
}
