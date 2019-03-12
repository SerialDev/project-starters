cmake_minimum_required(VERSION 3.0) # minimum requirement for Hunter

include("cmake/HunterGate.cmake") # teach your project about Hunter (before project())
HunterGate( # Latest release shown here: https://github.com/ruslo/hunter/releases
    URL "https://github.com/ruslo/hunter/archive/v0.20.17.tar.gz"
    SHA1 "d7d1d5446bbf20b78fa5ac1b52ecb67a01c3790e"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(opengl-init)

hunter_add_package(glew)
find_package(glew CONFIG REQUIRED)

hunter_add_package(SDL2)
find_package(SDL2 CONFIG REQUIRED)




hunter_add_package(glfw)
find_package(glfw3 REQUIRED)


set(${PROJECT_NAME}_SOURCES
  main.c
)


add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCES}
)

# add_executable(main main.c)

target_link_libraries(${PROJECT_NAME} glew::glew glfw)


