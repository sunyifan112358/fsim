cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME src )

# Structure
set( SUB_DIRECTORIES 
  simulation
  os
)
set( HEADER_FILES
)
set( SRC_FILES 
  fsim.cc
)

# Style check
set( CHECK_FILES ${HEADER_FILES} ${SRC_FILES})
add_style_check_target( ${FOLDER_NAME}
    "${CHECK_FILES}" 
    "${SUB_DIRECTORIES}" )

# Add sub directories
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )


