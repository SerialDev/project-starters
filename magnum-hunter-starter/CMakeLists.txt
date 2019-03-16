cmake_minimum_required(VERSION 3.2) # minimum requirement for Hunter

include("cmake/HunterGate.cmake") # teach your project about Hunter (before project())
HunterGate( # Latest release shown here: https://github.com/ruslo/hunter/releases
    URL "https://github.com/ruslo/hunter/archive/v0.23.127.tar.gz"
    SHA1 "2cd79807cb829127896811f8afa15e790b6bde19"
)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# project(download-magnum)

project(MagnumPrimitivesExample)

# DOCUMENTATION_START {
hunter_add_package(magnum)
find_package(Magnum CONFIG REQUIRED
    GL
    MeshTools
    Primitives
    Shaders
    Sdl2Application)

add_executable(magnum-primitives PrimitivesExample.cpp)
target_link_libraries(magnum-primitives PRIVATE
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::MeshTools
    Magnum::Primitives
    Magnum::Shaders)
# DOCUMENTATION_END }
