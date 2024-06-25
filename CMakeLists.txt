cmake_minimum_required(VERSION 3.27)
project(whac_a_rat)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(whac_a_rat
        Weapon.cpp
        Weapon.h
        Player.cpp
        Player.h
        Rat.cpp
        Rat.h
        NerdRat.cpp
        NerdRat.h
        StupidRat.cpp
        StupidRat.h
        MilitaryRat.cpp
        MilitaryRat.h
        BreslauRat.cpp
        BreslauRat.h
        BaseballBat.cpp
        BaseballBat.h
        Shoe.cpp
        Shoe.h
        Randomizer.cpp
        Randomizer.h
        Gun.cpp
        Gun.h
        main.cpp
        Controller.cpp
        Controller.h)
