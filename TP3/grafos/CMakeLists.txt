cmake_minimum_required(VERSION 3.19)
project(grafos)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafos main.cpp Grafo.cpp Grafo.h Vertice.cpp Vertice.h Lista.h Nodo.h Floyd.cpp Floyd.h)