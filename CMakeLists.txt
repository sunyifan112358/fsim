cmake_minimum_required( VERSION 2.8 )

# Project definition
project( fsim )

# List of sub_directories
set( SUB_DIRECTORIES src)

# Include from path root
include_directories( ${CMAKE_SOURCE_DIR} )

# Style check
include( style_check.cmake )
add_style_check_target( check "" "${SUB_DIRECTORIES}" )

# GTest
include( ExternalProject )
enable_testing()
ExternalProject_Add( googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  PREFIX gtest
  INSTALL_COMMAND ""
)

# CXX Flags
set( CMAKE_CXX_FLAGS "-Wall -Werror -pthread -std=c++11")

# Sub dirctories
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )



