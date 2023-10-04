cmake_minimum_required(VERSION 3.0)
project(OpenGLBook)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(external/glfw)

include_directories(external/glad/include/ external/glfw/include/
                    external/glm/)

file(GLOB PROJECT_HEADERS headers/*.hpp)
file(GLOB VENDOR_SOURCES external/glad/src/glad.c)
file(GLOB PROJECT_SOURCES chapter1/*.cpp)
file(GLOB PROJECT_CONFIGS CMakeLists.txt ../.gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})
source_group("Sources" FILES ${PROJECT_SOURCES})



message(STATUS ${PROJECT_SOURCES})
message(STATUS ${PROJECT_HEADERS})
message(STATUS ${VENDOR_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

    add_executable(hello_triangle "chapter1/hello_triangle.cpp" ${PROJECT_HEADERS}
    ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
    ${VENDORS_SOURCES})
target_link_libraries(hello_triangle glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})
# target_include_directories(hello_triangle "external/glad/include/")
set_target_properties(hello_triangle PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

