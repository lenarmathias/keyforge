cmake_minimum_required(VERSION 3.25)

project(keyforge
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(keyforge
    src/main.cpp
    src/password_generator.cpp
    src/terminal_ui.cpp
)
