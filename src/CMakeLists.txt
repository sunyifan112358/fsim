cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME src )

# Structure
set( SUB_DIRECTORIES 
  simulation
)
set( HEADER_FILES
)
set( SRC_FILES 
  fsim.cc
)

# Add sub directories
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )

# Style check
set( CHECK_FILES ${HEADER_FILES} ${SRC_FILES})
add_style_check_target(${FOLDER_NAME}_check
  "${CHECK_FILES}" "${SUB_DIRECTORIES}")

# fsim main program
add_executable(fsim fsim.cc)

# Libraries
target_link_libraries(fsim 
  simulation
)
