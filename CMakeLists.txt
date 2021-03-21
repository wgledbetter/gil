project(GIL LANGUAGES CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt.")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dep)
set(PYBIND11_CPP_STANDARD -std=c++17)

set(INCLUDE_DIRS ${PYBIND11_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS})
set(LINK_LIBS ${PYTHON_LIBRARIES})

list(APPEND COMPILE_FLAGS "-Xlinker -undefined")
list(APPEND COMPILE_FLAGS "-Xlinker dynamic_lookup")
list(APPEND COMPILE_FLAGS "-flto=thin")

list(APPEND LINKER_FLAGS "-Xlinker -undefined -Xlinker dynamic_lookup -flto=thin")

pybind11_add_module(gil main.cpp)
target_compile_options(gil PUBLIC ${COMPILE_FLAGS})
target_include_directories(gil PRIVATE ${INCLUDE_DIRS})
target_link_libraries(gil PRIVATE ${LINK_LIBS})
set_target_properties(gil PROPERTIES LINK_FLAGS ${LINKER_FLAGS})
