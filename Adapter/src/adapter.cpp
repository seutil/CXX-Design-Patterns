#include <power-sockets.hpp>
#include <plugs.hpp>
#include <power-socket-adapters.hpp>

int main()
{
    using namespace Adapter;

    std::unique_ptr usa_plug = std::make_unique<UsaPlug>();
    std::shared_ptr europe_power_socket = std::make_shared<EuropePowerSocket>();
    std::shared_ptr europe_to_usa = std::make_shared<EuropeToUsaPowerSocketAdapter>(europe_power_socket);

    usa_plug->connect(europe_to_usa);
    usa_plug->disconnect();

    return 0;
}
