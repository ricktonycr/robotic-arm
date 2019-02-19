cmake_minimum_required (VERSION 3.13)
project (Robotic)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(robotic robotic.cxx)

target_link_libraries(robotic glfw glm ${OPENGL_LIBRARIES})