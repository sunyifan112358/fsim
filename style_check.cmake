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
message(${SOURCE_DIR})

# Check if cpp_lint.py exists
# find_file(CPP_LINT_PY NAMES cpplint.py DOC "Google cpp style scan program.")
# if(NOT CPP_LINT_PY)
#   message ( FATAL_ERROR "cpplint.py not found")
# endif()



function(add_style_check_target TARGET_NAME SOURCES_LIST SUB_DIRS)

  if(NOT SOURCES_LIST)
    add_custom_target(${TARGET_NAME}
      COMMENT "Linting ${TARGET_NAME}"
      VERBATIM)
  elseif(SOURCES_LIST)
    foreach( a ${SOURCE_LIST})
      message(${a})
    endforeach (a)
    #list(REMOVE_DUPLICATES SOURCE_LIST)
    #list(SORT SOURCES_LIST)
    add_custom_target(${TARGET_NAME}
      COMMAND "${CMAKE_COMMAND}" -E chdir
      "${CMAKE_CURRENT_SOURCE_DIR}"
      "${SOURCE_DIR}/cpplint/cpplint.py"
      ${SOURCES_LIST}
      DEPENDS ${SOURCES_LIST}
      COMMENT "Linting ${TARGET_NAME}"
      VERBATIM)
  endif()

  # Add sub directories as targets
  foreach( DIR ${SUB_DIRS} )
    add_dependencies(${TARGET_NAME} ${DIR}_check )
  endforeach( DIR )

endfunction()
