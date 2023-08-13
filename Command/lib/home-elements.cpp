#include <iostream>
#include "home-elements.hpp"
using namespace HomeStation;

const int MAX_CHANNEL_ID = 100;
const int MAX_VOLUME = 100;

void
OutdoorLight::on()
{
    if (m_light_on)
    {
        std::cout << "The outdoor light is already on\n";
        return;
    }

    std::cout << "Turn on the outdoor light\n";
    m_light_on = true;
}

void
OutdoorLight::off()
{
    if (!m_light_on)
    {
        std::cout << "The outdoor light is already off\n";
        return;
    }

    std::cout << "Turn off the outdoor light\n";
    m_light_on = false;
}

void
CeillingLight::on()
{
    if (m_light_on)
    {
        std::cout << "The cailling light is already on\n";
        return;
    }

    std::cout << "Turn on the ceilling light\n";
    m_light_on = true;
}

void
CeillingLight::off()
{
    if (!m_light_on)
    {
        std::cout << "The ceilling light is already off\n";
        return;
    }

    std::cout << "Turn off the ceilling light\n";
    m_light_on = false;
}

void
TV::on()
{
    if (m_on)
    {
        std::cout << "The TV is already working\n";
        return;
    }

    std::cout << "Turn on the TV\n";
    m_on = true;
}

void
TV::off()
{
    if (!m_on)
    {
        std::cout << "The TV is already turned off\n";
        return;
    }

    std::cout << "Turn off the TV\n";
    m_on = false;
}

int
TV::channel() const
{
    return m_channel;
}

void
TV::set_channel(int new_channel)
{
    if (!m_on)
    {
        std::cout << "TV is turned off\n";
        return;
    }
    else if (new_channel < 0 || new_channel > MAX_CHANNEL_ID)
    {
        std::cout << "The specified channel is not exists\n";
        return;
    }
    else if (new_channel == m_channel)
    {
        std::cout << "Channel is already used\n";
        return;
    }

    std::cout << "Setting up new channel\n";
    m_channel = new_channel;
}

int
TV::volume() const
{
    return m_volume;
}

void
TV::set_volume(int new_volume)
{
    if (!m_on)
    {
        std::cout << "TV is turned off\n";
        return;
    }
    else if (new_volume < 0 || new_volume > MAX_VOLUME)
    {
        std::cout << "The specified volume is invalid\n";
        return;
    }
    else if (new_volume == m_volume)
    {
        std::cout << "New volume is equal to the current one\n";
        return;
    }

    std::cout << "Setting up volume to " << new_volume << "\n";
    m_volume = new_volume;
}

void
Stereo::on()
{
    if (m_on)
    {
        std::cout << "The stereo is already working\n";
        return;
    }

    std::cout << "Turning on the stereo\n";
    m_on = true;
}

void
Stereo::off()
{
    if (!m_on)
    {
        std::cout << "The stereo is already turned off\n";
        return;
    }

    std::cout << "Turning off the stereo\n";
    m_on = false;
}

void
GarageDoor::up()
{
    if (m_up)
    {
        std::cout << "The door is already opened\n";
        return;
    }

    std::cout << "Lift the garage door\n";
    m_up = true;
}

void
GarageDoor::down()
{
    if (!m_up)
    {
        std::cout << "The door is already closed\n";
        return;
    }

    std::cout << "Closing the door\n";
    m_up = false;
}

void
GarageDoor::light_on()
{
    if (m_light_on)
    {
        std::cout << "Garage light is already turned on";
        return;
    }

    std::cout << "Turning on the garage light\n";
    m_light_on = true;
}

void
GarageDoor::light_off()
{
    if (!m_light_on)
    {
        std::cout << "Garage light is already turned off\n";
        return;
    }

    std::cout << "Turning off the garage light\n";
    m_light_on = false;
}
