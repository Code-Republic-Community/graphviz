# include(CTest)

add_executable(base_template test.cpp)
target_link_libraries(base_template gtest_main)
add_test(NAME base_template COMMAND base_template)

add_executable(edge_class_test edgetest.cpp ../examples/golden_graph/edge.cpp)
target_link_libraries(edge_class_test gtest_main)
add_test(NAME edge_class_test COMMAND edge_class_test)
