#pragma once
#include <iostream>

namespace DuckUSim {
class IFlyBehavior {
public:
    virtual void fly() const = 0;
    virtual ~IFlyBehavior() = default;
};

class Fly : public IFlyBehavior {
public:
    inline void fly() const override { std::cout << "I'm flying\n"; }
};

class Fall : public IFlyBehavior {
public:
    inline void fly() const override { std::cout << "I'm falling\n"; }
};

class ISwimBehavior {
public:
    virtual void swim() const = 0;
    virtual ~ISwimBehavior() = default;
};

class Swim : public ISwimBehavior {
public:
    inline void swim() const override { std::cout << "I'm swiming\n"; }
};

class Drown : public ISwimBehavior {
public:
    inline void swim() const override { std::cout << "I'm drowing\n"; }
};

class IQuackBehavior {
public:
    virtual void quack() const = 0;
    virtual ~IQuackBehavior() = default;
};

class Quack : public IQuackBehavior {
public:
    inline void quack() const override { std::cout << "Quack... quack...\n"; }
};

class Squeak : public IQuackBehavior {
public:
    inline void quack() const override { std::cout << "<Squeak>... <squeak>\n"; }
};

class Muted : public IQuackBehavior {
public:
    inline void quack() const override { std::cout << "<Muted>\n"; }
};
}
