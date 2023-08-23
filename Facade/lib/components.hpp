#pragma once
#include <memory>
#include <vector>

namespace HomeCinema {
class IInteractive {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual ~IInteractive() = default;
};

class Speaker : public IInteractive {
public:
    void on() override;
    void off() override;
};

class Amplifier : public IInteractive {
public:
    void on() override;
    void off() override;
};

class DvdPlayer : public IInteractive {
public:
    void on() override;
    void off() override;
};

class Screen : public IInteractive {
public:
    void on() override;
    void off() override;
};

class CinemaFacade : public IInteractive {
public:
    CinemaFacade();
    void on() override;
    void off() override;
protected:
    std::unique_ptr<Screen> m_screen;
    std::unique_ptr<Amplifier> m_amplifier;
    std::unique_ptr<DvdPlayer> m_dvd_player;
    std::vector<std::shared_ptr<Speaker>> m_speakers;
};
}
