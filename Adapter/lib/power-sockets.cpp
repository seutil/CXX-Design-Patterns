#include "power-sockets.hpp"
using namespace Adapter;

PowerSocket::PowerSocket(const std::string& name,
                         const int& voltage)
    : m_name{name},
      m_voltage{voltage}
{}

const std::string& PowerSocket::name() const {
    return m_name;
}

const int& PowerSocket::voltage() const {
    return m_voltage;
}

UsaPowerSocket::UsaPowerSocket()
    : PowerSocket("USA", 120)
{}

EuropePowerSocket::EuropePowerSocket()
    : PowerSocket("Europe", 220)
{}
