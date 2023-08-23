#pragma once

namespace Starbuzz {
class CoffeineBeverage {
public:
    void make() const;
    virtual ~CoffeineBeverage() = default;
protected:
    void boil_water() const;
    void pour_in_cup() const;
    virtual bool use_condiments() const;
    virtual void brew() const = 0;
    virtual void add_condiments() const = 0;
};

class Coffee : public CoffeineBeverage {
protected:
    bool use_condiments() const override;
    void brew() const override;
    void add_condiments() const override;
};

class Tea : public CoffeineBeverage {
protected:
    void brew() const override;
    void add_condiments() const override;
};
}
