# include(CTest)

add_executable(base_template test.cpp)
target_link_libraries(base_template gtest_main)
add_test(NAME base_template COMMAND base_template)