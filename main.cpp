#include <iostream>
#include <string>
#include "weather_app.h"
#include "weather_api.h"
#include "location_service.h"

int main() {
    WeatherApp app;
    
    while (true) {
        std::cout << "\nWeather Application\n";
        std::cout << "1. Current Weather\n";
        std::cout << "2. Weather Forecast\n";
        std::cout << "3. Weather Alerts\n";
        std::cout << "4. Change Location\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                app.showCurrentWeather();
                break;
            case 2:
                app.showForecast();
                break;
            case 3:
                app.showAlerts();
                break;
            case 4:
                app.changeLocation();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid option!\n";
        }
    }
    return 0;
}
