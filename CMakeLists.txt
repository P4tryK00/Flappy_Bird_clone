cmake_minimum_required(VERSION 4.3)
project(Flappy_Bird_clone LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Pobieranie biblioteki SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} main.cpp
        Game.cpp
        DEFINITIONS.h
        Bird.cpp
        Bird.h
        StateMachine.cpp
        StateMachine.h
        GameState.cpp
        GameState.h
        MenuState.cpp
        MenuState.h
        ResourceManager.cpp
        ResourceManager.h
        TextureManager.cpp
        TextureManager.h
        Pipe.cpp
        Pipe.h
        State.h
        FontManager.cpp
        FontManager.h
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Audio)