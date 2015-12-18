include( ExternalProject )
enable_testing()
ExternalProject_Add( googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  PREFIX gtest
  INSTALL_COMMAND ""
)
ExternalProject_Get_Property( googletest BINARY_DIR )
ExternalProject_Get_Property( googletest SOURCE_DIR )
add_library( gtest UNKNOWN IMPORTED )
add_library( gtest_main UNKNOWN IMPORTED )
add_library( gmock UNKNOWN IMPORTED )
add_library( gmock_main UNKNOWN IMPORTED )
set_target_properties( gtest PROPERTIES IMPORTED_LOCATION 
  ${BINARY_DIR}/googlemock/gtest/libgtest.a )
set_target_properties( gtest_main PROPERTIES IMPORTED_LOCATION 
  ${BINARY_DIR}/googlemock/gtest/libgtest_main.a )
set_target_properties( gmock PROPERTIES IMPORTED_LOCATION 
  ${BINARY_DIR}/googlemock/libgmock.a )
set_target_properties( gmock_main PROPERTIES IMPORTED_LOCATION 
  ${BINARY_DIR}/googlemock/libgmock_main.a )
add_dependencies( gtest googletest )
add_dependencies( gtest_main googletest )
add_dependencies( gmock googletest )
add_dependencies( gmock_main googletest )
include_directories( ${SOURCE_DIR}/googletest/include )
include_directories( ${SOURCE_DIR}/googlemock/include )


