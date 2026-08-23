cmake_minimum_required(VERSION 3.23)

project(AutonomyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(autonomy_sim)

target_sources(autonomy_sim
  PRIVATE
    src/main.cpp
    src/Vec2.cpp
    src/VehicleState.cpp
)

target_include_directories(autonomy_sim PRIVATE
    include
)