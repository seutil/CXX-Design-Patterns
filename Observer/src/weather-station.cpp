#include <weather-station.hpp>

int main()
{
    using namespace WeatherStation;

    std::unique_ptr weather_data = std::make_unique<WeatherData>();
    std::shared_ptr current_weather_display = std::make_unique<CurrentWeatherDisplay>();
    std::shared_ptr statistics_weather_display = std::make_unique<StaticticsWeatherDisplay>();
    weather_data->add_display(current_weather_display);
    weather_data->add_display(statistics_weather_display);
    weather_data->set_measurements(80, 65, 30.4);
	weather_data->set_measurements(82, 70, 29.2);
	weather_data->set_measurements(78, 90, 29.2);
    weather_data->remove_display(statistics_weather_display);
    weather_data->set_measurements(62, 90, 28.1f);
    return 0;
}
