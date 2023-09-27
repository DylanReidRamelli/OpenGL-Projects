cmake_minimum_required(VERSION 3.20)
project(OpenGLBook)

include(cmake/options.cmake)
include(cmake/functions.cmake)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW3 REQUIRED)



# INCLUDES OF DEPENDENCIES
list(APPEND OGL_BUILD_INCLUDES ${GLEW_INCLUDE_DIR})
list(APPEND OGL_BUILD_INCLUDES "${GLFW3_DIR}/include/")
list(APPEND OGL_BUILD_INCLUDES ${GLUT_INCLUDE_DIRS})
list(APPEND OGL_BUILD_INCLUDES ${OPENGL_INCLUDE_PATH})


# LIBRARIES OF DEPENDENCIES
list(APPEND OGL_DEP_LIBRARIES "/usr/local/lib/libGLEW.dylib")
list(APPEND OGL_DEP_LIBRARIES "/usr/local/lib/libglfw3.a")
list(APPEND OGL_DEP_LIBRARIES ${GLUT_LIBRARIES})
list(APPEND OGL_DEP_LIBRARIES ${OPENGL_LIBRARIES})


# Could take out backend. core modules
set(OGL_MODULES chapter1)

foreach(MODULE ${OGL_MODULES})
  add_subdirectory("${MODULE}")
endforeach(MODULE)


message(STATUS "OGL_SOURCES:${OGL_SOURCES}")
message(STATUS "OGL_HEADERS:${OGL_HEADERS}")
message(STATUS "OGL_BUILD_INCLUDES:${OGL_BUILD_INCLUDES}")
message(STATUS "OGL_DEP_INCLUDES:${OGL_DEP_INCLUDES}")


add_library(OGL ${OGL_SOURCES} ${OGL_HEADERS})

foreach(include ${OGL_BUILD_INCLUDES})
  target_include_directories(OGL BEFORE PUBLIC $<BUILD_INTERFACE:${include}>)
endforeach()


target_include_directories(
  OGL BEFORE
  PUBLIC $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
         $<INSTALL_INTERFACE:include>)

target_include_directories(OGL PUBLIC ${OGL_DEP_INCLUDES})
target_link_libraries(OGL PUBLIC ${OGL_DEP_LIBRARIES})

# target_link_libraries(OGL OpenGL GLUT GLEW GLFW3)

# get_cmake_property(_variableNames VARIABLES)
# list(SORT _variableNames)
# foreach(_variableName ${_variableNames})
#   message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
