cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME simulation )

# Structure
set( SUB_DIRECTORIES )
set( HEADER_FILES
  simulation.h
  simulation_impl.h
)
set( SRC_FILES 
  simulation_impl.cc
)

# Add sub directories
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )

# Style check
set( CHECK_FILES ${HEADER_FILES} ${SRC_FILES})
add_style_check_target(${FOLDER_NAME}_check
  "${CHECK_FILES}" "${SUB_DIRECTORES}")

# Add library
add_library(simulation ${SRC_FILES})
