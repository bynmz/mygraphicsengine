cmake_minimum_required(VERSION 3.12)

# set the project name
project(MyGraphicsEngine)
add_definitions("-Wall" "-g")
include_directories(${PROJECT_SOURCE_DIR})
file(GLOB MyGraphicsEngine_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

# add the executable
add_executable(MyGraphicsEngine ${MyGraphicsEngine_SRC})

#add the Glfw library
find_library(GLFW_LIB glfw3)
target_link_libraries(MyGraphicsEngine PRIVATE "${GLFW_LIB}")

find_path(GLFW_INC glfw3)
target_include_directories(MyGraphicsEngine PRIVATE "${GLFW_INC}")


#add vulkan library
find_path(VULKAN_INC vulkan)
target_include_directories(MyGraphicsEngine PRIVATE "${VULKAN_INC}")

find_library(VULKAN_LIB vulkan)
target_link_libraries(MyGraphicsEngine PRIVATE "${VULKAN_LIB}")
