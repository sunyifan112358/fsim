cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME src_simulation )

# Structure
set( SUB_DIRECTORIES 
  test
)
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
add_style_check_target(${FOLDER_NAME} 
  "${CHECK_FILES}"
  "${SUB_DIRCTORIES}")

# Add library
add_library(simulation ${SRC_FILES})
