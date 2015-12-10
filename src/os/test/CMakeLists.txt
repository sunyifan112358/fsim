cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME src_os_test )

set( HEADER_FILES
  mock_operating_system.h
  mock_process_factory.h
  mock_process.h
  mock_program_loader.h
  mock_thread_factory.h
)
set( SRC_FILES 
  program_starter_impl_test.cc
)

# Style check
set( CHECK_FILES ${HEADER_FILES} ${SRC_FILES})
add_style_check_target( ${FOLDER_NAME} 
  "${CHECK_FILES}" 
  "")

# Program starter test
add_executable( program_starter_test program_starter_impl_test.cc)
target_link_libraries( program_starter_test
  os 
  gtest
  gmock
  gmock_main
)
add_test( program_starter_test program_starter_test )
