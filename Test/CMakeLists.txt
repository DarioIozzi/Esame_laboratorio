cmake_minimum_required(VERSION 3.20)
project(Test)

add_subdirectory(googletest-main)
set(gtest_SOURCE_DIR, ./googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(testSourceFiles runAllTests.cpp GameCharacterTest.cpp)
add_executable(runTest ${testSourceFiles})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SFML/include)
target_link_libraries(runTest gtest gtest_main sfml-system sfml-audio sfml-window sfml-graphics sfml-network sfml-main core)