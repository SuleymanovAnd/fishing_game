cmake_minimum_required(VERSION 3.22)

set (MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)
set(SOURCE
        main.cpp
        field.cpp
        )
set(INCLUDE
        ${MY_DIRECTORY}/field.h
        ${MY_DIRECTORY}/fish.h
        )


add_executable(fishing_game ${SOURCE} ${INCLUDE})
target_include_directories (fishing_game PUBLIC ${MY_DIRECTORY})