# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


add_executable(LearnOpenGL_1_1 main.cpp)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(LearnOpenGL_1_1 PRIVATE glfw glab OpenGL::GL)

