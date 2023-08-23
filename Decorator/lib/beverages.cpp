#include "beverages.hpp"
using namespace Starbuzz;

Beverage::Beverage(const std::string& name,
                   const double& cost,
                   const Size& size)
    : m_name{name},
      m_cost{cost},
      m_size{size}
{}

const std::string& Beverage::name() const {
    return m_name;
}

const double& Beverage::cost() const {
    return m_cost;
}

const Beverage::Size& Beverage::size() const {
    return m_size;
}

void Beverage::set_size(const Size& size) {
    m_size = size;
}

HouseBlend::HouseBlend(const Size& size)
    : Beverage("House Blend Coffee", .89, size)
{}

DarkRoast::DarkRoast(const Size& size)
    : Beverage("Dark Roast Coffee", .99, size)
{}

Decaf::Decaf(const Size& size)
    : Beverage("Decaf Coffee", 1.05, size)
{}

Espresso::Espresso(const Size& size)
    : Beverage("Epsresso Coffee", 1.99, size)
{}
