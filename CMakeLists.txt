cmake_minimum_required(VERSION 3.15)
project(SFML_Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

set(SRC_LIST Screen.cpp Game.cpp MenuScreen.cpp main.cpp GameScreen.cpp Player.cpp PlayerAnimation.cpp)
add_executable(touhoufangame ${SRC_LIST})

target_link_libraries(touhoufangame PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)