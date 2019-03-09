cmake_minimum_required(VERSION 3.0) # minimum requirement for Hunter

include("cmake/HunterGate.cmake") # teach your project about Hunter (before project())
HunterGate( # Latest release shown here: https://github.com/ruslo/hunter/releases
    URL "https://github.com/ruslo/hunter/archive/v0.20.17.tar.gz"
    SHA1 "d7d1d5446bbf20b78fa5ac1b52ecb67a01c3790e"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(sdl-init)

hunter_add_package(SDL2)
find_package(SDL2 CONFIG REQUIRED)

if(ANDROID)
  add_library(main SHARED main.cpp)
else()
  add_executable(main main.cpp Game.cpp)
endif()

target_link_libraries(main
    SDL2::SDL2main
    SDL2::SDL2)

