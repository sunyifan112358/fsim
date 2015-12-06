function(add_style_check_target TARGET_NAME SOURCES_LIST SUB_DIRS)

  message("${SOURCE_LIST}")
  # Check if python is available
  find_package(PythonInterp)
  if(NOT PYTHONINTERP_FOUND)
    message("python not found")
    return()
  endif()

  # Check if cpp_lint.py exists
  find_file(CPP_LINT_PY NAMES cpplint.py DOC "Google cpp style scan program.")
  if(NOT CPP_LINT_PY)
    message ("cpplint.py not found")
  endif()

  # Check if clang_format exists
  find_file(CLANG_FORMAT NAMES clang-format DOC "Clang format tool")
  if(NOT CLANG_FORMAT)
    message ("clang-format not found")
  endif()

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
      clang-format -style=Google -i
      ${SOURCES_LIST}
      COMMAND "${CMAKE_COMMAND}" -E chdir
      "${CMAKE_CURRENT_SOURCE_DIR}"
      "cpplint.py"
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
