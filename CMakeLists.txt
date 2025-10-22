cmake_minimum_required(VERSION 3.10)
project(WeatherApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(weather_app 
    src/main.cpp
    src/weather_api.cpp
    src/weather_app.cpp
)

target_include_directories(weather_app PRIVATE include)
target_link_libraries(weather_app PRIVATE 
    CURL::libcurl
    nlohmann_json::nlohmann_json
)
