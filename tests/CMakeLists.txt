#include(CTest)

add_executable(base_template test.cpp)
target_link_libraries(base_template gtest_main)
add_test(NAME base_template COMMAND base_template)

add_executable(graph_test test_graph.cpp ../examples/golden_graph/graph.cpp ../examples/golden_graph/node.cpp ../examples/golden_graph/edge.cpp)
target_link_libraries(graph_test gtest_main)
add_test(NAME graph_test COMMAND graph_test)
target_include_directories(graph_test PUBLIC ../libs/json)

add_executable(nodeTest nodeTest.cpp ../examples/golden_graph/node.cpp ../examples/golden_graph/edge.cpp)
target_link_libraries(nodeTest gtest_main)
add_test(NAME nodeTest COMMAND nodeTest)

add_executable(edge_class_test edgetest.cpp ../examples/golden_graph/edge.cpp)
target_link_libraries(edge_class_test gtest_main)
add_test(NAME edge_class_test COMMAND edge_class_test)
