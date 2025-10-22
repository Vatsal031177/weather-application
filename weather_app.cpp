#include "weather_app.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

WeatherApp::WeatherApp() {
    api = std::make_unique<WeatherAPI>("YOUR_API_KEY");
    currentCity = locationService.getDefaultCity();
}

void WeatherApp::displayWeatherData(const WeatherData& data) {
    std::cout << "\nCurrent Weather in " << currentCity << "\n";
    std::cout << "Temperature: " << std::fixed << std::setprecision(1) 
              << data.temperature << "°C\n";
    std::cout << "Humidity: " << data.humidity << "%\n";
    std::cout << "Conditions: " << data.description << "\n";
    std::cout << "Wind Speed: " << data.windSpeed << " m/s\n";
}

void WeatherApp::showCurrentWeather() {
    try {
        WeatherData current = api->getCurrentWeather(currentCity);
        displayWeatherData(current);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void WeatherApp::startAutoUpdate() {
    std::thread([this]() {
        while (true) {
            updateWeatherData();
            std::this_thread::sleep_for(std::chrono::minutes(15));
        }
    }).detach();
}

void WeatherApp::changeLocation() {
    std::cout << "Enter city name: ";
    std::getline(std::cin, currentCity);
    showCurrentWeather();
}
