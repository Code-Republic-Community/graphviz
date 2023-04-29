# include(CTest)

add_executable(base_template test.cpp)
target_link_libraries(base_template gtest_main)
add_test(NAME base_template COMMAND base_template)

add_executable(nodeTest nodeTest.cpp ../examples/golden_graph/node.cpp ../examples/golden_graph/edge.cpp)
target_link_libraries(nodeTest gtest_main)
add_test(NAME nodeTest COMMAND nodeTest)