cmake_minimum_required(VERSION 3.10)

SET(PROJECT_NAME "PruebaDeCmake")
SET(NRVO_PROJECT_NAME "PruebaDeNrvo")

#project(${PROJECT_NAME} VERSION 1.0)
project(${NRVO_PROJECT_NAME} VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)


#add_executable(${PROJECT_NAME} Source.cpp)
add_executable(${NRVO_PROJECT_NAME} nrvotest.cpp)