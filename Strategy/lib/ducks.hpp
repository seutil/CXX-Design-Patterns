#pragma once
#include <memory>
#include "behaviors.hpp"

namespace DuckUSim
{

class Duck
{
public:
    inline void fly()   const { m_fly_behavior->fly(); };
    inline void swim()  const { m_swim_behavior->swim(); };
    inline void quack() const { m_quack_behavior->quack(); };
    virtual ~Duck() = default;
protected:
    Duck(std::unique_ptr<IFlyBehavior>&& fly_behavior,
         std::unique_ptr<ISwimBehavior>&& swim_behavior,
         std::unique_ptr<IQuackBehavior>&& quack_behavior)
        : m_fly_behavior{std::move(fly_behavior)},
          m_swim_behavior{std::move(swim_behavior)},
          m_quack_behavior{std::move(quack_behavior)}
    {};
    
    std::unique_ptr<IFlyBehavior> m_fly_behavior;
    std::unique_ptr<ISwimBehavior> m_swim_behavior;
    std::unique_ptr<IQuackBehavior> m_quack_behavior;
};

class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck(std::make_unique<Fly>(), std::make_unique<Swim>(), std::make_unique<Quack>())
    {} 
};

class RedheadDuck : public Duck
{
public:
    RedheadDuck() : Duck(std::make_unique<Fly>(), std::make_unique<Swim>(), std::make_unique<Quack>())
    {}
};

class RubberDuck : public Duck
{
public:
    RubberDuck() : Duck(std::make_unique<Fall>(), std::make_unique<Swim>(), std::make_unique<Quack>())
    {}
};

class ModelDuck : public Duck
{
public:
    ModelDuck() : Duck(std::make_unique<Fall>(), std::make_unique<Drown>(), std::make_unique<Muted>())
    {}
};

}

