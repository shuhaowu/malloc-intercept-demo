cmake_minimum_required(VERSION 3.18)
project(malloc-intercept-demo)

add_library(malloc_monitoring
  SHARED
  src/monitoring.cc
)

target_include_directories(malloc_monitoring
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(malloc_monitoring
  PUBLIC
  cxx_std_20
)

add_executable(program
  src/program.cc
)

target_link_libraries(program
  PRIVATE
  "$<IF:$<CONFIG:Debug>,malloc_monitoring,>"
)

target_compile_features(program
  PUBLIC
  cxx_std_20
)

add_library(malloc_override
  SHARED
  src/malloc_override.cc
)

target_link_libraries(malloc_override
  PRIVATE
  malloc_monitoring
)

target_compile_features(malloc_override
  PUBLIC
  cxx_std_20
)
