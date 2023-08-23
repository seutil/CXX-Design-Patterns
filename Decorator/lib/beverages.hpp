#pragma once
#include <string>

namespace Starbuzz {
class Beverage {
public:
    enum class Size {
        SHORT,
        TALL,
        GRANDE
    };

    const std::string& name() const;
    const double& cost() const;
    const Size& size() const;
    void set_size(const Size& size);
    virtual ~Beverage() = default;
protected:
    Beverage(const std::string& name,
             const double& cost,
             const Size& size);
    std::string m_name;
    double m_cost;
    Size m_size;
};

class HouseBlend : public Beverage {
public:
    HouseBlend(const Size& size = Size::TALL);
};

class DarkRoast : public Beverage {
public:
    DarkRoast(const Size& size = Size::TALL);
};

class Decaf : public Beverage {
public:
    Decaf(const Size& size = Size::TALL);
};

class Espresso : public Beverage {
public:
    Espresso(const Size& size = Size::TALL);
};
}
