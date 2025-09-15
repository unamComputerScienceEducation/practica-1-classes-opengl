cmake_minimum_required(VERSION 3.24)

project(monsters_tournament LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/src/Main.cpp
    ${PROJECT_SOURCE_DIR}/src/Batalla.cpp
    ${PROJECT_SOURCE_DIR}/src/Torneo.cpp
    ${PROJECT_SOURCE_DIR}/src/io_files/Lectura.cpp
    ${PROJECT_SOURCE_DIR}/src/io_files/Escritura.cpp)