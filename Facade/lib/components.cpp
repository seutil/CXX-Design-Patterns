#include <iostream>
#include "components.hpp"
using namespace HomeCinema;

void
Speaker::on()
{
    std::cout << "Speaker is turned on\n";
}

void
Speaker::off()
{
    std::cout << "Speaker is turned off\n";
}

void
Amplifier::on()
{
    std::cout << "Amplifier is turned on\n";
}

void
Amplifier::off()
{
    std::cout << "Amplifier is turned off\n";
}

void
DvdPlayer::on()
{
    std::cout << "Insert DVD disk\n";
}

void
DvdPlayer::off()
{
    std::cout << "Eject DVD disk\n";
}

void
Screen::on()
{
    std::cout << "Screen is turned on\n";
}

void
Screen::off()
{
    std::cout << "Screen is turned off\n";
}

CinemaFacade::CinemaFacade()
    : m_screen(std::make_unique<Screen>()),
      m_amplifier(std::make_unique<Amplifier>()),
      m_dvd_player{std::make_unique<DvdPlayer>()},
      m_speakers{
        std::make_shared<Speaker>(),
        std::make_shared<Speaker>(),
        std::make_shared<Speaker>(),
        std::make_shared<Speaker>(),
        std::make_shared<Speaker>(),
        std::make_shared<Speaker>()
      }
{}

void
CinemaFacade::on()
{
    std::cout << "Start...\n";
    m_dvd_player->on();
    for (const auto& s : m_speakers)
        s->on();
    
    m_amplifier->on();
    std::cout << "Done\n";
}

void
CinemaFacade::off()
{
    std::cout << "Stop...\n";
    m_dvd_player->off();
    for (const auto& s : m_speakers)
        s->off();

    m_amplifier->off();
    std::cout << "Done\n";
}
