cmake_minimum_required(VERSION 3.27)
project(whac_a_rat)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

include_directories(.)

# SFML SETUP FOR WINDOWS
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

# SFML SETUP
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

configure_file(assets/fonts/VT323-Regular.ttf ${CMAKE_CURRENT_BINARY_DIR}/assets/fonts/VT323-Regular.ttf COPYONLY)
configure_file(assets/icon.png ${CMAKE_CURRENT_BINARY_DIR}/assets/icon.png COPYONLY)
configure_file(assets/textures/kanaliza.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/kanaliza.png COPYONLY)
configure_file(assets/textures/stupid.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/stupid.png COPYONLY)
configure_file(assets/textures/nerd.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/nerd.png COPYONLY)
configure_file(assets/textures/military.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/military.png COPYONLY)
configure_file(assets/textures/breslau.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/breslau.png COPYONLY)

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
        Controller.h
        Manager.cpp
        Manager.h
        View.cpp
        View.h
        Leaderboard.cpp
        Leaderboard.h
        Palette.cpp
        Palette.h
        Label.cpp
        Label.h
)

target_link_libraries(whac_a_rat sfml-graphics sfml-audio)