#pragma once
#include <vector>
#include <unordered_map>
#include "home-commands.hpp"
#include "home-elements.hpp"

namespace HomeStation
{

class RemoteController
{
public:
    RemoteController();
    std::shared_ptr<ICommand> get_command(const std::string& command);
    std::vector<std::string> commands() const;
protected:
    std::shared_ptr<OutdoorLight> m_outdoor_light;
    std::shared_ptr<CeillingLight> m_ceilling_light;
    std::shared_ptr<TV> m_tv;
    std::shared_ptr<Stereo> m_stereo;
    std::shared_ptr<GarageDoor> m_garage_door;
    std::unordered_map<std::string, std::shared_ptr<ICommand>> m_commands;
};

}

