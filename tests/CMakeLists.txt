#include(CTest)

add_executable(base_template test.cpp)
target_link_libraries(base_template gtest_main)
add_test(NAME base_template COMMAND base_template)

add_executable(graph_test test_graph.cpp ../examples/golden_graph/graph.cpp ../examples/golden_graph/node.cpp ../examples/golden_graph/edge.cpp)
target_link_libraries(graph_test gtest_main)
add_test(NAME graph_test COMMAND graph_test)
target_include_directories(graph_test PUBLIC ../libs/nlohmann)

