#include <assert.h>
#include <iostream>
#include "plugs.hpp"
using namespace Adapter;

void UsaPlug::connect(std::shared_ptr<PowerSocket> power_socket) {
    m_power_socket = std::dynamic_pointer_cast<UsaPowerSocket>(power_socket);
    assert(!m_power_socket.expired());
    std::cout << "Plug to " << power_socket->name() << " socket\n";
}

void UsaPlug::disconnect() {
    if (m_power_socket.expired()) {
        std::cout << "Already disconnected\n";
        return;
    }

    std::cout << "Disconnecting...\n";
    m_power_socket.reset();
}

void EuropePlug::connect(std::shared_ptr<PowerSocket> power_socket) {
    m_power_socket = std::dynamic_pointer_cast<EuropePowerSocket>(power_socket);
}

void EuropePlug::disconnect() {
    if (m_power_socket.expired()) {
        std::cout << "Already disconnected\n";
        return;
    }

    std::cout << "Disconnecting...\n";
    m_power_socket.reset();
}