#include "weather_api.h"
#include <json.hpp>
#include <sstream>

using json = nlohmann::json;

WeatherAPI::WeatherAPI(const std::string& key) : apiKey(key) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    baseUrl = "http://api.openweathermap.org/data/2.5/";
}

WeatherAPI::~WeatherAPI() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

size_t WeatherAPI::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string WeatherAPI::makeRequest(const std::string& endpoint) {
    std::string readBuffer;
    
    if(curl) {
        std::string url = baseUrl + endpoint + "&appid=" + apiKey + "&units=metric";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            throw std::runtime_error("Failed to get weather data");
        }
    }

    return readBuffer;
}

WeatherData WeatherAPI::getCurrentWeather(const std::string& city) {
    std::string response = makeRequest("weather?q=" + city);
    json data = json::parse(response);
    
    WeatherData weather;
    weather.temperature = data["main"]["temp"];
    weather.humidity = data["main"]["humidity"];
    weather.description = data["weather"][0]["description"];
    weather.windSpeed = data["wind"]["speed"];
    
    return weather;
}
