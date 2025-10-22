std::vector<Location> WeatherAPI::searchLocations(const std::string& query) {
    std::string response = makeRequest("geo/1.0/direct?q=" + query + "&limit=5");
    json data = json::parse(response);
    
    std::vector<Location> locations;
    for (const auto& item : data) {
        Location loc;
        loc.city = item["name"];
        loc.country = item["country"];
        loc.latitude = item["lat"];
        loc.longitude = item["lon"];
        locations.push_back(loc);
    }
    
    return locations;
}

WeatherData WeatherAPI::getWeatherByCoordinates(double lat, double lon) {
    std::stringstream endpoint;
    endpoint << "weather?lat=" << lat << "&lon=" << lon;
    
    std::string response = makeRequest(endpoint.str());
    json data = json::parse(response);
    
    WeatherData weather;
    weather.temperature = data["main"]["temp"];
    weather.humidity = data["main"]["humidity"];
    weather.description = data["weather"][0]["description"];
    weather.windSpeed = data["wind"]["speed"];
    
    return weather;
}
