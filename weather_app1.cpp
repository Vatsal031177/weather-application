void WeatherApp::searchLocation() {
    std::string query;
    std::cout << "Enter location to search: ";
    std::getline(std::cin, query);

    try {
        std::vector<Location> results = locationService.searchLocation(query);
        
        if (results.empty()) {
            std::cout << "No locations found.\n";
            return;
        }

        std::cout << "\nFound Locations:\n";
        for (size_t i = 0; i < results.size(); i++) {
            std::cout << i + 1 << ". " << results[i].city << ", " 
                     << results[i].country << "\n";
        }

        std::cout << "\nSelect location number (0 to cancel): ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice > 0 && choice <= static_cast<int>(results.size())) {
            currentCity = results[choice - 1].city;
            locationService.addToHistory(results[choice - 1]);
            showCurrentWeather();
        }
    } catch (const std::exception& e) {
        std::cout << "Error searching location: " << e.what() << "\n";
    }
}

void WeatherApp::showSearchHistory() {
    auto history = locationService.getSearchHistory();
    
    if (history.empty()) {
        std::cout << "No search history available.\n";
        return;
    }

    std::cout << "\nRecent Searches:\n";
    for (size_t i = 0; i < history.size(); i++) {
        std::cout << i + 1 << ". " << history[i].city << ", " 
                 << history[i].country << "\n";
    }

    std::cout << "\nSelect location number (0 to cancel): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice > 0 && choice <= static_cast<int>(history.size())) {
        currentCity = history[choice - 1].city;
        showCurrentWeather();
    }
}
