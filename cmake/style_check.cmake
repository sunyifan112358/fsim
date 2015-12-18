# Check if python is available
find_package(PythonInterp)
if(NOT PYTHONINTERP_FOUND)
  message( FATAL_ERROR "python not found")
endif()

include( ExternalProject )
ExternalProject_Add(cpplint
  PREFIX cpplint
  GIT_REPOSITORY https://github.com/google/styleguide.git
  GIT_TAG gh-pages
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)
ExternalProject_Get_Property(cpplint SOURCE_DIR)
set( CPPLINT ${SOURCE_DIR}/cpplint/cpplint.py )

function(add_style_check_target DIRECTORY SOURCE_LIST SUB_DIRECTORIES)


  if( DIRECTORY )
    set( TARGET_NAME ${DIRECTORY}_check )
  else( DIRECTORY )
    set( TARGET_NAME check )
  endif( DIRECTORY )


  if( SOURCE_LIST )
    add_custom_target(${TARGET_NAME}
      COMMAND "${CMAKE_COMMAND}" -E chdir
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CPPLINT}"
        ${SOURCE_LIST}
      DEPENDS cpplint ${SOURCE_LIST}
      COMMENT "Linting ${TARGET_NAME}"
      VERBATIM)
  else( SOURCE_LIST )
     add_custom_target(${TARGET_NAME}
     COMMENT "Linting ${TARGET_NAME}"
     VERBATIM)
  endif( SOURCE_LIST )

  foreach(SUB_DIR ${SUB_DIRECTORIES})
    if( DIRECTORY )
      add_dependencies( ${TARGET_NAME} ${DIRECTORY}_${SUB_DIR}_check )
    else( DIRECTORY )
      add_dependencies( ${TARGET_NAME} ${SUB_DIR}_check )
    endif( DIRECTORY )
  endforeach(SUB_DIR)

endfunction()
