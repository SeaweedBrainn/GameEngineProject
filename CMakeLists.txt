cmake_minimum_required(VERSION 3.25.0) #Describes the minimum CMake version required
  project(GameEngine VERSION 0.1.0 LANGUAGES C CXX) #Define a project name and the languages used

  find_package(GLFW3 REQUIRED)
  find_package(GLEW REQUIRED)
  find_package(GLM REQUIRED)

  # Add all .cpp files in the src directory and its subdirectories
  file(GLOB_RECURSE CPP_SOURCES src/*.cpp)

  # Add all .h files in the src directory and its subdirectories
  file(GLOB_RECURSE HEADER_FILES src/*.h)

  add_executable(${PROJECT_NAME} src/main.cpp ${CPP_SOURCES} ${HEADER_FILES}) 

  target_link_libraries(${PROJECT_NAME} glfw GLEW::GLEW glm::glm glu::glu)

  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17) 