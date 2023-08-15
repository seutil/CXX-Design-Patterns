#include "power-socket-adapters.hpp"
using namespace Adapter;

EuropeToUsaPowerSocketAdapter::EuropeToUsaPowerSocketAdapter(std::shared_ptr<EuropePowerSocket> europe_power_socket)
    : m_europe_socket_adapter{europe_power_socket}
{}
