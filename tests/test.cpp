#include "gtest/gtest.h"

int foo(int a) { return ++a; }

TEST(test_template, first_test) {
    EXPECT_EQ(1, foo(0));
    EXPECT_EQ(2, foo(1));
    EXPECT_EQ(6, foo(5));
    EXPECT_EQ(40320, foo(40319));
}
