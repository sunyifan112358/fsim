cmake_minimum_required( VERSION 2.8 )

# Sub dirctories
set( SUB_DIRECTORIES 
  simulation
)
foreach( SUB_DIR ${SUB_DIRECTORIES} )
  add_subdirectory( ${SUB_DIR} )
endforeach( SUB_DIR )

# fsim main program
add_executable(fsim fsim.cc)

# Libraries
target_link_libraries(fsim 
  simulation
)
