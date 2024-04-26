cmake_minimum_required(VERSION 3.0.0)

#cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Tetris LANGUAGES CXX)
include_directories(include)

file(GLOB SRCS src/*.cpp main.cpp)
add_library(Tetris STATIC ${SRCS})


set_property(TARGET Tetris PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(Tetris PROPERTIES OUTPUT_NAME Tetris)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -fsanitize=address,undefined -std=c++11 -lm -lX11" )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-error -pedantic -fsanitize=address,undefined -std=c++11 -lm -lX11" )

#set(TARGET_SOURCES main.cpp

#    GameField.cpp
#    XConnection.cpp

#)

set(TARGET_HEADERS include)

#    GameField.hpp
#    XConnection.hpp
#    FieldBase.hpp

#    iDrawable.hpp
#)

add_executable("game_${PROJECT_NAME}" ${SRCS} ${TARGET_HEADERS})#${TARGET_SOURCES} ${TARGET_HEADERS})
#set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
