cmake_minimum_required(VERSION 3.10.0) #Describes the minimum CMake version required
  project(GameEngine VERSION 0.1.0 LANGUAGES C CXX) #Define a project name and the languages used

  include(CTest) #Use this for testing purposes
  enable_testing() #Enable Testing

  add_executable(GameEngine main.cpp) # Add the executable file to the project

  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 17) #Set the target to the CMake project and specify version of C++ used