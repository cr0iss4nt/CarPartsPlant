#include <gtest/gtest.h>
#include "../src/cutVector.hpp"

TEST(cutVectorTest, cutVectorFunction) {
    std::vector<int> vec0 = {0, 1, 2, 3, 4, 5, 6};
    std::vector<int> vec = vec0;
    std::vector<int> vec1 = {0, 1, 2, 3, 4};
    std::vector<int> vec2 = {};
    cutVector(vec, 50);
    EXPECT_EQ(vec, vec0);
    cutVector(vec, 0);
    EXPECT_EQ(vec, vec0);
    cutVector(vec, -50);
    EXPECT_EQ(vec, vec0);
    cutVector(vec, 2);
    EXPECT_EQ(vec, vec1);
    cutVector(vec, 5);
    EXPECT_EQ(vec, vec2);
}