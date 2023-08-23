#pragma once
#include <vector>

namespace WeatherStation {
class IWeatherDisplay {
public:
    virtual void update(const double& temperature,
                        const double& humidity,
                        const double& pressure) = 0;
    virtual ~IWeatherDisplay() = default;
};

class CurrentWeatherDisplay : public IWeatherDisplay {
public:
    void update(const double& temperture,
                const double& humidity,
                const double& pressure) override;
};

class StaticticsWeatherDisplay : public IWeatherDisplay {
public:
    void update(const double& temperatue,
                const double& humidity,
                const double& pressure) override;
protected:
    std::vector<double> m_temperatures;
    std::vector<double> m_humidities;
    std::vector<double> m_pressures;
};
}
