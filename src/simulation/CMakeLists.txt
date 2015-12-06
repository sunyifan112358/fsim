cmake_minimum_required( VERSION 2.8 )

# Sub dirctories
set( SUB_DIRECTORIES )
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )

# Library
set( HEADER_FILES
  Simulation.h
  SimulationImpl.h
)
set( SRC_FILES 
  SimulationImpl.cc
)
add_library(simulation ${SRC_FILES})
