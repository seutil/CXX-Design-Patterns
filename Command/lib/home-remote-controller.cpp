#include <string>
#include "home-remote-controller.hpp"
using namespace HomeStation;


RemoteController::RemoteController()
    : m_outdoor_light{std::make_shared<OutdoorLight>()},
      m_ceilling_light{std::make_shared<CeillingLight>()},
      m_tv{std::make_shared<TV>()},
      m_stereo{std::make_shared<Stereo>()},
      m_garage_door{std::make_shared<GarageDoor>()},
      m_commands{
        { "outdoor on", std::make_shared<OutdoorLightOnCommand>(m_outdoor_light) },
        { "outdoor off", std::make_shared<OutdoorLightOffCommand>(m_outdoor_light) },
        { "ceilling on", std::make_shared<CeillingLightOnCommand>(m_ceilling_light) },
        { "ceilling off", std::make_shared<CeillingLightOffCommand>(m_ceilling_light) },
        { "tv on", std::make_shared<TVPowerOnCommand>(m_tv) },
        { "tv off", std::make_shared<TVPowerOffCommand>(m_tv) },
        { "tv increase volume", std::make_shared<TVIncreaseVolumeCommand>(m_tv) },
        { "tv decrease volume", std::make_shared<TVDecreaseVolumeCommand>(m_tv) },
        { "tv next channel", std::make_shared<TVNextChannelCommand>(m_tv) },
        { "tv previouse channel", std::make_shared<TVPreviouseChannelCommand>(m_tv) },
        { "stereo on", std::make_shared<StereoOnCommand>(m_stereo) },
        { "stereo off", std::make_shared<StereoOffCommand>(m_stereo) },
        { "garage up", std::make_shared<GarageDoorUpCommand>(m_garage_door) },
        { "garage down", std::make_shared<GarageDoorDownCommand>(m_garage_door) },
        { "garage light on", std::make_shared<GarageDoorTurnOnLightCommand>(m_garage_door) },
        { "garage light off", std::make_shared<GarageDoorTurnOffLightComman>(m_garage_door) }
    }
{}

std::shared_ptr<ICommand>
RemoteController::get_command(const std::string& command)
{
    return m_commands.at(command);
}

std::vector<std::string>
RemoteController::commands() const
{
    std::vector<std::string> out;
    for (auto& p : m_commands)
        out.push_back(p.first);
    
    return out;
}
