#include <gtest/gtest.h>

#include "Arithmetic.hpp"

TEST(ArithmeticTest, AddTest) {
    Arithmetic arithmetic;
    arithmetic.add("10", "20");
    EXPECT_EQ(arithmetic.getResult(), "30");
}

TEST(ArithmeticTest, SubtractTest) {
    Arithmetic arithmetic;
    arithmetic.subtract("30", "20");
    EXPECT_EQ(arithmetic.getResult(), "10");
}

TEST(ArithmeticTest, MultiplyTest) {
    Arithmetic arithmetic;
    arithmetic.multiply("10", "20");
    EXPECT_EQ(arithmetic.getResult(), "200");
}

TEST(ArithmeticTest, DivideTest) {
    Arithmetic arithmetic;
    arithmetic.divide("20", "5");
    EXPECT_EQ(arithmetic.getResult(), "4");
}
