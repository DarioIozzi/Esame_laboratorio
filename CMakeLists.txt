cmake_minimum_required(VERSION 3.20)
project(Esame_laboratorio)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(source_files
        main.cpp
        GameCharacter.h
        GameCharacter.cpp
        Observer.h
        MapView.h
        MapView.cpp
        Controller.h
        Controller.cpp
        Display.h
        StlAStar.h
        StlAStar.cpp
        Fsa.h
        WorldMap.h
        WorldMap.cpp
        Enemy.h
        Subject.h)

add_executable(Esame_laboratorio ${source_files})
add_library(core ${source_files})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SFML/include)
target_link_libraries(Esame_laboratorio sfml-system sfml-audio sfml-window sfml-graphics sfml-network sfml-main core)