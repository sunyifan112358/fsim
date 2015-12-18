cmake_minimum_required( VERSION 2.8 )

# Project definition
project( fsim )

# CMAKE Modules
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )

# List of sub_directories
set( SUB_DIRECTORIES src )

# Include from path root
include_directories( ${CMAKE_SOURCE_DIR} )

# Style check
include( style_check )
add_style_check_target( "" "" "${SUB_DIRECTORIES}" )

# GTest
include( google_test )

# Coveralls
option(COVERALLS "Generate coveralls data" OFF)
if( COVERALLS )
  include( coveralls )
  coveralls_turn_on_coverage()
 
  file( GLOB_RECURSE ALL_SRCS RELATIVE "${PROJECT_SOURCE_DIR}" "*.cc")
  set( COVERAGE_SRCS ${ALL_SRCS} )
  message( "${COVERAGE_SRCS}" )
  coveralls_setup( "${COVERAGE_SRCS}" ON )
endif()

# CXX Flags
set( CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wall -Werror -pthread -std=c++11" )

# Sub dirctories
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )

# fsim main program
add_executable( fsim src/fsim.cc )

# Libraries
target_link_libraries( fsim 
  simulation
)

# Guarantee style is good
add_dependencies( fsim check )

