cmake_minimum_required(VERSION 4.2)
project(Dijkstra_basico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dijkstra_basico main.cpp
        Grafo.cpp
        Grafo.h)
