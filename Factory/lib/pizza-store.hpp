#pragma once
#include "pizza.hpp"

namespace Pizzeria {
class PizzaStore {
public:
    std::shared_ptr<Pizza> order_pizza(const std::string& type) const;
    virtual ~PizzaStore() = default;
protected:
    virtual void decorate_pizza(std::shared_ptr<Pizza>& pizza) const = 0;
};

class NewYorkPizzaStore : public PizzaStore {
protected:
    void decorate_pizza(std::shared_ptr<Pizza>& pizza) const override;
};

class ChicagoPizzaStore : public PizzaStore {
protected:
    void decorate_pizza(std::shared_ptr<Pizza>& pizza) const override;
};

class CaliforniaPizzaStore : public PizzaStore {
protected:
    void decorate_pizza(std::shared_ptr<Pizza>& pizza) const override;
};
}
