cmake_minimum_required(VERSION 4.3)
project(fuzzy-umbrella CXX)

set(CMAKE_C_STANDARD 23)

include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
)
FetchContent_MakeAvailable(SFML)

add_executable(fuzzy-umbrella
        src/main.cpp
        src/game.cpp                        include/game.hpp

        src/scene.cpp                       include/scene.hpp
        src/scene_manager.cpp               include/scene_manager.hpp
        src/scenes/menu_scene.cpp           include/scenes/menu_scene.hpp
        src/scenes/game_scene.cpp           include/scenes/game_scene.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(fuzzy-umbrella PRIVATE ${CMAKE_SOURCE_DIR})