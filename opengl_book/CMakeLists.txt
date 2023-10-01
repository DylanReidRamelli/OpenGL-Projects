cmake_minimum_required(VERSION 3.20)
project(OpenGLBook C CXX)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(OpenGLBook/Vendor/glfw)


file(GLOB PROJECT_HEADERS headers/*.hpp)
file(GLOB VENDOR_SOURCES OpenGLBook/Vendor/glad/src/glad.c)

file(GLOB PROJECT_CONFIGS CMakeLists.txt
  .gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})


add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_CONFIGS}
                               ${VENDORS_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})