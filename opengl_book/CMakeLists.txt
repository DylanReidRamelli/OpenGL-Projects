cmake_minimum_required(VERSION 3.20)
project(OpenGLBook C CXX)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(external/glfw)

include_directories(external/glad/include/ external/glfw/include/
                    external/glm/include/)

file(GLOB PROJECT_HEADERS headers/*.hpp)
file(GLOB VENDOR_SOURCES external/glad/src/glad.c)

file(GLOB PROJECT_CONFIGS CMakeLists.txt .gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(chapter1 "chapter1/main.cpp" ${PROJECT_HEADERS}
                        ${PROJECT_CONFIGS} ${VENDORS_SOURCES})
target_link_libraries(chapter1 glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})
set_target_properties(chapter1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                          ${CMAKE_BINARY_DIR}/chapter1)
set_target_properties(chapter1 PROPERTIES LINKER_LANGUAGE CXX)
