add_executable( simulation_test simulation_impl_test.cc)
target_link_libraries( simulation_test
  simulation 
  gtest
  gmock
)
add_test( simulation_test simulation_test )
