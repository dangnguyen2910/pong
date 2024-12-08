cmake_minimum_required(VERSION 3.5.0)
project(Pong VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

add_executable(
    Pong 
    src/main.cpp 
    src/Game.cpp)
    
target_link_libraries(Pong PRIVATE sfml-graphics sfml-window sfml-system)



