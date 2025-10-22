#pragma once
#include <string>
#include <vector>

struct WeatherData {
    double temperature;
    int humidity;
    std::string description;
    double windSpeed;
    std::string timestamp;
};

struct WeatherAlert {
    std::string type;
    std::string description;
    std::string startTime;
    std::string endTime;
    std::string severity;
};
