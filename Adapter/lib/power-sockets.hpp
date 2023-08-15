#pragma once
#include <string>

namespace Adapter
{

class PowerSocket
{
public:
    const std::string& name() const;
    const int& voltage() const;
    virtual ~PowerSocket() = default;
protected:
    PowerSocket(const std::string& name,
                const int& voltage);
    std::string m_name;
    int m_voltage;
};

class UsaPowerSocket : public PowerSocket
{
public:
    UsaPowerSocket();
};

class EuropePowerSocket : public PowerSocket
{
public:
    EuropePowerSocket();
};

}
