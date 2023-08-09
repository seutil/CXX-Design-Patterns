#include <algorithm>
#include "weather-station.hpp"
using namespace WeatherStation;

void
WeatherData::set_measurements(const double& temperature,
                              const double& humidity,
                              const double& pressure)
{
    m_temperature = temperature;
    m_humidity = humidity;
    m_pressure = pressure;
    notify_displays();
}

void
WeatherData::add_display(std::shared_ptr<IWeatherDisplay> display)
{
    m_displays.push_back(display);
}

void 
WeatherData::remove_display(std::shared_ptr<IWeatherDisplay> display)
{
    m_displays.erase(
        std::remove_if(
            m_displays.begin(),
            m_displays.end(),
            [&](const std::weak_ptr<IWeatherDisplay>& wptr) { return wptr.expired() || wptr.lock() == display; }
        ),
        m_displays.end()
    );
}

void
WeatherData::notify_displays() const
{
    for (auto& wptr : m_displays)
    {
        if (wptr.expired())
            continue;

        wptr.lock()->update(m_temperature, m_humidity, m_pressure);
    }
}

