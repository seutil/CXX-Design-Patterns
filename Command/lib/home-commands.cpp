#include "home-commands.hpp"
using namespace HomeStation;

OutdoorLightOnCommand::OutdoorLightOnCommand(std::shared_ptr<OutdoorLight> outdoor_light)
    : m_outdoor_light{outdoor_light}
{}

void OutdoorLightOnCommand::execute() {
    m_outdoor_light.lock()->on();
}

OutdoorLightOffCommand::OutdoorLightOffCommand(std::shared_ptr<OutdoorLight> outdoor_light)
    : m_outdoor_light{outdoor_light}
{}

void OutdoorLightOffCommand::execute() {
    m_outdoor_light.lock()->off();
}

CeillingLightOnCommand::CeillingLightOnCommand(std::shared_ptr<CeillingLight> ceilling_light)
    : m_ceilling_light{ceilling_light}
{}

void CeillingLightOnCommand::execute() {
    m_ceilling_light.lock()->on();
}

CeillingLightOffCommand::CeillingLightOffCommand(std::shared_ptr<CeillingLight> ceilling_light)
    : m_ceilling_light{ceilling_light}
{}

void CeillingLightOffCommand::execute() {
    m_ceilling_light.lock()->off();
}

TVPowerOnCommand::TVPowerOnCommand(std::shared_ptr<TV> tv)
    : m_tv{tv}
{}

void TVPowerOnCommand::execute() {
    m_tv.lock()->on();
}

TVPowerOffCommand::TVPowerOffCommand(std::shared_ptr<TV> tv)
    : m_tv{tv}
{}

void TVPowerOffCommand::execute() {
    m_tv.lock()->off();
}

TVIncreaseVolumeCommand::TVIncreaseVolumeCommand(std::shared_ptr<TV> tv)
    : m_tv{tv}
{}

void TVIncreaseVolumeCommand::execute() {
    auto tv = m_tv.lock();
    tv->set_volume(tv->volume() + 5);
}

TVDecreaseVolumeCommand::TVDecreaseVolumeCommand(std::shared_ptr<TV> tv)
    : m_tv{tv}
{}

void TVDecreaseVolumeCommand::execute() {
    auto tv = m_tv.lock();
    tv->set_volume(tv->volume() - 5);
}

TVNextChannelCommand::TVNextChannelCommand(std::shared_ptr<TV> tv)
    : m_tv{tv}
{}

void TVNextChannelCommand::execute() {
    auto tv = m_tv.lock();
    tv->set_channel(tv->channel() + 1);
}

TVPreviouseChannelCommand::TVPreviouseChannelCommand(std::shared_ptr<TV> tv)
    : m_tv{tv}
{}

void TVPreviouseChannelCommand::execute() {
    auto tv = m_tv.lock();
    tv->set_channel(tv->channel() - 1);
}

StereoOnCommand::StereoOnCommand(std::shared_ptr<Stereo> stereo)
    : m_stereo{stereo}
{}

void StereoOnCommand::execute() {
    m_stereo.lock()->on();
}

StereoOffCommand::StereoOffCommand(std::shared_ptr<Stereo> stereo)
    : m_stereo{stereo}
{}

void StereoOffCommand::execute() {
    m_stereo.lock()->off();
}

GarageDoorUpCommand::GarageDoorUpCommand(std::shared_ptr<GarageDoor> garage_door)
    : m_garage_door{garage_door}
{}

void GarageDoorUpCommand::execute() {
    m_garage_door.lock()->up();
}

GarageDoorDownCommand::GarageDoorDownCommand(std::shared_ptr<GarageDoor> garage_door)
    : m_garage_door{garage_door}
{}

void GarageDoorDownCommand::execute() {
    m_garage_door.lock()->down();
}

GarageDoorTurnOnLightCommand::GarageDoorTurnOnLightCommand(std::shared_ptr<GarageDoor> garage_door)
    : m_garage_door{garage_door}
{}

void GarageDoorTurnOnLightCommand::execute() {
    m_garage_door.lock()->light_on();
}

GarageDoorTurnOffLightComman::GarageDoorTurnOffLightComman(std::shared_ptr<GarageDoor> garade_door)
    : m_garage_door{garade_door}
{}

void GarageDoorTurnOffLightComman::execute() {
    m_garage_door.lock()->light_off();
}
