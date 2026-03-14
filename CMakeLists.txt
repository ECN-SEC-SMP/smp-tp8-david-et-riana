cmake_minimum_required(VERSION 3.20)
project(smp_tp8_david_et_riana)

set(CMAKE_CXX_STANDARD 20)

add_executable(smp_tp8_david_et_riana main.cpp 
            animaux.cpp
            animaux.h
            plateau.cpp
            plateau.h
            jeu.cpp
            jeu.h)
