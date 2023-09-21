cmake_minimum_required(VERSION 3.20)
project(Esame_laboratorio)

set(CMAKE_CXX_STANDARD 14)

add_executable(Esame_laboratorio main.cpp GameCharacter.cpp GameCharacter.h Observer.h Subject.h MapView.cpp MapView.h Controller.cpp Controller.h Display.h StlAStar.h Fsa.h Findpath.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SFML/include)
target_link_libraries(Esame_laboratorio sfml-system sfml-audio sfml-window sfml-graphics sfml-network sfml-main)