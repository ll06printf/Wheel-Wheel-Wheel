//
// Created by ll06 on 24-12-18.
//

#include <gtest/gtest.h>

#include "TriW/Snippet/Constraint.h"

#include <vector>

int test_fn(int n) {return 0;}

TEST(ConstraintTest, Concept) {
  using namespace TriW::Constraint;

  EXPECT_TRUE((same_as<int, int>));
  EXPECT_FALSE((same_as<int, int&>));
  EXPECT_FALSE((same_as<int&, int>));
  EXPECT_FALSE((same_as<int &&, int &>));
  EXPECT_FALSE((same_as<int, float>));

  EXPECT_TRUE(integral<int>);
  EXPECT_FALSE(integral<float>);
  EXPECT_TRUE(integral<char>);
  EXPECT_TRUE(integral<signed>);
  EXPECT_FALSE((integral<std::vector<int>>));

  EXPECT_TRUE((invocable<decltype(test_fn), int>));
  EXPECT_TRUE((invocable<std::greater<void>, int, int>));

  EXPECT_TRUE((convertible_to<int, float>));
  EXPECT_TRUE((convertible_to<float, int>));
  EXPECT_FALSE((convertible_to<std::vector<int>, int>));
}