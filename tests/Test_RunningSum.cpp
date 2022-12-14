#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

#include "Solution.h"

// The fixture for testing class Solution. From google test primer.
class SolutionTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    SolutionTest() {
        // You can do set-up work for each test here.
        fails = 0;
    }

    virtual ~SolutionTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        if (fails > 0) {
            fprintf(stderr, "TEST FAILED! %u failures found!\n", fails);
        }
    }

    // Objects declared here can be used by all tests in the test case for Solution.
    Solution s;
    unsigned fails;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(SolutionTest, RunningSum1) {
    std::vector<int> input{1, 2, 3, 4};
    std::vector<int> actualResult(s.runningSum(input));
    std::vector<int> expectedResult{1, 3, 6, 10};
    EXPECT_THAT(actualResult, ::testing::ContainerEq(expectedResult));
    fails += ::testing::Test::HasFailure();
}

TEST_F(SolutionTest, RunningSum2) {
    std::vector<int> input{1, 1, 1, 1, 1};
    std::vector<int> actualResult(s.runningSum(input));
    std::vector<int> expectedResult{1, 2, 3, 4, 5};
    EXPECT_THAT(actualResult, ::testing::ContainerEq(expectedResult));
    fails += ::testing::Test::HasFailure();
}

TEST_F(SolutionTest, RunningSum3) {
    std::vector<int> input{3, 1, 2, 10, 1};
    std::vector<int> actualResult(s.runningSum(input));
    std::vector<int> expectedResult{3, 4, 6, 16, 17};
    EXPECT_THAT(actualResult, ::testing::ContainerEq(expectedResult));
    fails += ::testing::Test::HasFailure();
}

// }  // namespace - could surround SolutionTest in a namespace