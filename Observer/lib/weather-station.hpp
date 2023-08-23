#pragma once
#include <memory>
#include <vector>
#include "weather-displays.hpp"

namespace WeatherStation {
class WeatherData {
public:
    void set_measurements(const double& temperature,
                          const double& humidity,
                          const double& pressure);
    void add_display(std::shared_ptr<IWeatherDisplay> display);
    void remove_display(std::shared_ptr<IWeatherDisplay> display);
protected:
    void notify_displays() const;

    double m_temperature;
    double m_humidity;
    double m_pressure;
    std::vector<std::weak_ptr<IWeatherDisplay>> m_displays;
};
}
