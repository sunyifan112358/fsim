cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME src_simulation_test )

set( HEADER_FILES
)
set( SRC_FILES 
  simulation_impl_test.cc
)

# Style check
set( CHECK_FILES ${HEADER_FILES} ${SRC_FILES})
add_style_check_target( ${FOLDER_NAME} 
  "${CHECK_FILES}" 
  "")

add_executable( simulation_test simulation_impl_test.cc)
target_link_libraries( simulation_test
  simulation 
  gtest
  gmock
  gmock_main
)
add_test( simulation_test simulation_test )
