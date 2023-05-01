#include "../examples/golden_graph/edge.hpp"
#include "gtest/gtest.h"

TEST(test_template, first_test) {
    Edge test(12, Direction::DESTINATION);
    Edge test2(13, Direction::SOURCE);
    EXPECT_EQ(12, test.getID());
    EXPECT_EQ(13, test2.getID());
    EXPECT_EQ(static_cast<int16_t>(Direction::DESTINATION),
              static_cast<int16_t>(test.getDirection()));
    EXPECT_EQ(static_cast<int16_t>(Direction::SOURCE), static_cast<int16_t>(test2.getDirection()));
}
