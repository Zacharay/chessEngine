cmake_minimum_required(VERSION 3.10)

project(chessEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
	src/bitboards.cpp 
	src/board.cpp 
	src/evaluate.cpp 
	src/helpers.cpp
	src/init.cpp
	src/main.cpp
	src/movegen.cpp
	src/perfit.cpp
	src/polybook.cpp
	src/search.cpp
	src/tt.cpp
	src/uci.cpp
	src/zobrist.cpp
)

include_directories(includes)
add_executable(chessEngine ${SOURCES})

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})