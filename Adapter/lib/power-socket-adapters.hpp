#pragma once
#include <memory>
#include "power-sockets.hpp"

namespace Adapter {
class EuropeToUsaPowerSocketAdapter : public UsaPowerSocket {
public:
    EuropeToUsaPowerSocketAdapter(std::shared_ptr<EuropePowerSocket> europe_power_socket);
protected:
    std::weak_ptr<EuropePowerSocket> m_europe_socket_adapter;
};
}
