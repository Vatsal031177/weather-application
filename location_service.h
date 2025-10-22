#pragma once
#include <string>
#include <vector>

struct Location {
    std::string city;
    std::string country;
    double latitude;
    double longitude;
};

class LocationService {
private:
    std::vector<Location> searchHistory;
    std::string defaultCity;

public:
    LocationService();
    std::vector<Location> searchLocation(const std::string& query);
    void addToHistory(const Location& location);
    std::vector<Location> getSearchHistory() const;
    std::string getDefaultCity() const;
    void setDefaultCity(const std::string& city);
};
