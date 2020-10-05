cmake_minimum_required(VERSION 3.13)
project(RPi-Buzzer-Example)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPi-Buzzer-Example src/main.cpp)
target_link_libraries(${PROJECT_NAME} -lwiringPi)
