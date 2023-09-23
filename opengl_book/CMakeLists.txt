cmake_minimum_required(VERSION 3.20)
project(OpenGLBook)

include(cmake/options.cmake)
include(cmake/functions.cmake)

set(BOOK_MOUDULES chapter1)

foreach(MODULE ${BOOK_MOUDULES})
	add_subdirectory("${MODULE}")
endforeach()

list(APPEND BOOK_SOURCES main.cpp)

if(ENABLE_GLFW3)
  find_package(GLFW3)
  if(GLFW3_FOUND)
    message(STATUS "glfw3 found!\n")
    list(APPEND BOOK_BUILD_INCLUDES "${GLFW3_DIR}/include")
  else()
    message(STATUS "glfw3 NOT found!\n")
  endif()
endif()

if(ENABLE_GLEW)
  find_package(GLEW)
  if(GLEW_FOUND)
    message(STATUS "GLEW found!\n")
    list(APPEND BOOK_BUILD_INCLUDES ${GLEW_INCLUDE_DIR})
  else()
    message(STATUS "GLEW NOT found!\n")
  endif()
endif()

add_library(OpenGLBook ${BOOK_SOURCES} ${BOOK_HEADERS})

foreach(include ${BOOK_BUILD_INCLUDES})
  target_include_directories(OpenGLBook BEFORE PUBLIC $<BUILD_INTERFACE:${include}>)
endforeach()

add_executable(main main.cpp)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
