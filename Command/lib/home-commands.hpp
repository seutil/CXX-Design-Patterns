#pragma once
#include <memory>
#include "home-elements.hpp"

namespace HomeStation {
class ICommand {
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
};

class OutdoorLightOnCommand : public ICommand {
public: 
    OutdoorLightOnCommand(std::shared_ptr<OutdoorLight> outdoor_light);
    void execute() override;
protected:
    std::weak_ptr<OutdoorLight> m_outdoor_light;
};

class OutdoorLightOffCommand : public ICommand {
public: 
    OutdoorLightOffCommand(std::shared_ptr<OutdoorLight> outdoor_light);
    void execute() override;
protected:
    std::weak_ptr<OutdoorLight> m_outdoor_light;
};

class CeillingLightOnCommand : public ICommand {
public:
    CeillingLightOnCommand(std::shared_ptr<CeillingLight> ceilling_light);
    void execute() override;
protected:
    std::weak_ptr<CeillingLight> m_ceilling_light;
};

class CeillingLightOffCommand : public ICommand {
public:
    CeillingLightOffCommand(std::shared_ptr<CeillingLight> ceilling_light);
    void execute() override;
protected:
    std::weak_ptr<CeillingLight> m_ceilling_light;
};

class TVPowerOnCommand : public ICommand {
public:
    TVPowerOnCommand(std::shared_ptr<TV> tv);
    void execute() override;
protected:
    std::weak_ptr<TV> m_tv;
};

class TVPowerOffCommand : public ICommand {
public:
    TVPowerOffCommand(std::shared_ptr<TV> tv);
    void execute() override;
protected:
    std::weak_ptr<TV> m_tv;
};

class TVIncreaseVolumeCommand : public ICommand {
public:
    TVIncreaseVolumeCommand(std::shared_ptr<TV> tv);
    void execute() override;
protected:
    std::weak_ptr<TV> m_tv;
};

class TVDecreaseVolumeCommand : public ICommand {
public:
    TVDecreaseVolumeCommand(std::shared_ptr<TV> tv);
    void execute() override;
protected:
    std::weak_ptr<TV> m_tv;
};

class TVNextChannelCommand : public ICommand {
public:
    TVNextChannelCommand(std::shared_ptr<TV> tv);
    void execute() override;
protected:
    std::weak_ptr<TV> m_tv;
};

class TVPreviouseChannelCommand : public ICommand {
public:
    TVPreviouseChannelCommand(std::shared_ptr<TV> tv);
    void execute() override;
protected:
    std::weak_ptr<TV> m_tv;
};

class StereoOnCommand : public ICommand {
public:
    StereoOnCommand(std::shared_ptr<Stereo> stereo);
    void execute() override;
protected:
    std::weak_ptr<Stereo> m_stereo;
};

class StereoOffCommand : public ICommand {
public:
    StereoOffCommand(std::shared_ptr<Stereo> stereo);
    void execute() override;
protected:
    std::weak_ptr<Stereo> m_stereo;
};

class GarageDoorUpCommand : public ICommand {
public:
    GarageDoorUpCommand(std::shared_ptr<GarageDoor> garade_door);
    void execute() override;
protected:
    std::weak_ptr<GarageDoor> m_garage_door;
};

class GarageDoorDownCommand : public ICommand {
public:
    GarageDoorDownCommand(std::shared_ptr<GarageDoor> garade_door);
    void execute() override;
protected:
    std::weak_ptr<GarageDoor> m_garage_door;
};

class GarageDoorTurnOnLightCommand : public ICommand {
public:
    GarageDoorTurnOnLightCommand(std::shared_ptr<GarageDoor> garade_door);
    void execute() override;
protected:
    std::weak_ptr<GarageDoor> m_garage_door;
};

class GarageDoorTurnOffLightComman : public ICommand {
public:
    GarageDoorTurnOffLightComman(std::shared_ptr<GarageDoor> garade_door);
    void execute() override;
protected:
    std::weak_ptr<GarageDoor> m_garage_door;
};

}
