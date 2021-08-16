cmake_minimum_required(VERSION 3.20)
project(Esame_laboratorio)

set(CMAKE_CXX_STANDARD 14)

add_executable(Esame_laboratorio main.cpp GameCharacter.cpp GameCharacter.h Observer.h Subject.h MapView.cpp MapView.h Controller.cpp Controller.h Display.h)

include_directories(usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Esame_laboratorio sfml-system sfml-audio sfml-window sfml-graphics sfml-network)