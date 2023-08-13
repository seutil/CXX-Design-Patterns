#pragma once

namespace HomeStation
{

class OutdoorLight
{
public:
    void on();
    void off();
protected:
    bool m_light_on;
};

class CeillingLight
{
public:
    void on();
    void off();
protected:
    bool m_light_on;
};

class TV
{
public:
    void on();
    void off();
    int channel() const;
    void set_channel(int new_channel);
    int volume() const;
    void set_volume(int new_volume);
protected:
    bool m_on;
    int m_channel;
    int m_volume;
};

class Stereo
{
public:
    void on();
    void off();
protected:
    bool m_on;
};

class GarageDoor
{
public:
    void up();
    void down();
    void light_on();
    void light_off();
protected:
    bool m_up;
    bool m_light_on;
};

}
