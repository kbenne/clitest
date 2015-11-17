cmake_minimum_required(VERSION 3.4)

find_package(swig)

find_package(ruby)
include_directories(SYSTEM ${RUBY_INCLUDE_DIRS})

add_library(foo Foo.hpp Foo.cpp)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

add_custom_command(
  OUTPUT "Foo_wrap.cxx"
  COMMAND "${SWIG_EXECUTABLE}"
          "-ruby" "-c++"  
          "-I${CMAKE_SOURCE_DIR}" "-I${CMAKE_BINARY_DIR}"
          -o "${CMAKE_BINARY_DIR}/Foo_wrap.cxx"
          "${CMAKE_CURRENT_SOURCE_DIR}/Foo.i"
  DEPENDS Foo.hpp Foo.i
)

add_library(rubyfoo "${CMAKE_BINARY_DIR}/Foo_wrap.cxx")

add_executable(clitest main.cpp)
target_link_libraries(clitest rubyfoo foo ${RUBY_LIBRARY})

