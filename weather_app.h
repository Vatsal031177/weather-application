#pragma once
#include "weather_api.h"
#include "location_service.h"
#include <memory>

class WeatherApp {
private:
    std::unique_ptr<WeatherAPI> api;
    LocationService locationService;
    std::string currentCity;
    
    void displayWeatherData(const WeatherData& data);
    void updateWeatherData();

public:
    WeatherApp();
    void showCurrentWeather();
    void showForecast();
    void showAlerts();
    void changeLocation();
    void startAutoUpdate();
};
