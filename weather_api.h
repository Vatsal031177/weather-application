#pragma once
#include <string>
#include <curl/curl.h>
#include "weather_data.h"

class WeatherAPI {
private:
    std::string apiKey;
    std::string baseUrl;
    CURL* curl;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    std::string makeRequest(const std::string& endpoint);

public:
    WeatherAPI(const std::string& key);
    ~WeatherAPI();

    WeatherData getCurrentWeather(const std::string& city);
    std::vector<WeatherData> getForecast(const std::string& city, int days);
    std::vector<WeatherAlert> getAlerts(const std::string& city);
};
