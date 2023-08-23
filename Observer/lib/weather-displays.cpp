#include <numeric>
#include <iostream>
#include "weather-displays.hpp"
using namespace WeatherStation;

void CurrentWeatherDisplay::update(const double& temperature,
                                   const double& humidity,
                                   const double& pressure)
{
    std::cout << "====== CURRENT DISPLAY =====\n"
              << "Temperature: " << temperature << "\n"
              << "Humidity:    " << humidity << "\n"
              << "Pressure:    " << pressure << "\n"
              << "============================\n\n";
}

void StaticticsWeatherDisplay::update(const double& temperature,
                                      const double& humidity,
                                      const double& pressure)
{
    m_temperatures.push_back(temperature);
    m_humidities.push_back(humidity);
    m_pressures.push_back(pressure);
    std::cout << "===== STATISTICS DISPLAY =====\n"
              << "Average temperatue: " << std::accumulate(m_temperatures.begin(), m_temperatures.end(), 0.0) / m_temperatures.size() << "\n"
              << "Average humidity:   " << std::accumulate(m_humidities.begin(), m_humidities.end(), 0.0) / m_humidities.size() << "\n"
              << "Average pressure:   " << std::accumulate(m_pressures.begin(), m_pressures.end(), 0.0) / m_pressures.size() << "\n"
              << "==============================\n\n";
}
