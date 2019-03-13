cmake_minimum_required(VERSION 3.2) # minimum requirement for Hunter

include("cmake/HunterGate.cmake") # teach your project about Hunter (before project())
HunterGate( # Latest release shown here: https://github.com/ruslo/hunter/releases
    URL "https://github.com/ruslo/hunter/archive/v0.23.127.tar.gz"
    SHA1 "2cd79807cb829127896811f8afa15e790b6bde19"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(main)


# DOCUMENTATION_START {
hunter_add_package(imgui)
find_package(imgui CONFIG REQUIRED)

add_executable(imgui_test main.cpp)
target_link_libraries(imgui_test imgui::imgui)
# DOCUMENTATION_END }
