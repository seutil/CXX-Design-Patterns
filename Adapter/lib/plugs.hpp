#pragma once
#include <memory>
#include "power-sockets.hpp"

namespace Adapter {
class IPlug {
public:
    virtual void connect(std::shared_ptr<PowerSocket> power_socket) = 0;
    virtual void disconnect() = 0;
    virtual ~IPlug() = default;
};

class UsaPlug : public IPlug {
public:
    void connect(std::shared_ptr<PowerSocket> power_socket) override;
    void disconnect() override;
protected:
    std::weak_ptr<UsaPowerSocket> m_power_socket;
};

class EuropePlug : public IPlug {
public:
    void connect(std::shared_ptr<PowerSocket> power_socket) override;
    void disconnect() override;
protected:
    std::weak_ptr<EuropePowerSocket> m_power_socket;
};
}
