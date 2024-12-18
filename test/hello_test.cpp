//
// Created by ll06 on 24-12-17.
//

#include <gtest/gtest.h>

#include <iostream>

TEST(HelloTest, AlwaysPassed) {
  SUCCEED() << "The test used to test GTest framework is always passed.";
}