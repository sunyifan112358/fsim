cmake_minimum_required( VERSION 2.8 )
set( FOLDER_NAME src_os )

# Structure
set( SUB_DIRECTORIES 
  test
)
set( HEADER_FILES
  operating_system.h
  operating_system_impl.h
  process.h
  process_factory.h
  program.h
  program_starter.h
  program_starter_impl.h
  thread.h
  thread_factory.h
)
set( SRC_FILES 
  operating_system_impl.cc
  program_starter_impl.cc
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

# Add library
add_library(os ${SRC_FILES})
