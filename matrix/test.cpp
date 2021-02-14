#include <gtest/gtest.h>
#include "matrix.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(spiral, common1)
{
    Solution solve;

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    vector<int> res = solve.spiralOrder(matrix);

    EXPECT_EQ(judge_same_vector(res, result), true);
}

TEST(spiral, common2)
{
    Solution solve;

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    vector<int> res = solve.spiralOrder(matrix);

    EXPECT_EQ(judge_same_vector(res, result), true);
}

TEST(spiral, empty)
{
    Solution solve;

    vector<vector<int>> matrix = {};
    vector<int> result = {};
    vector<int> res = solve.spiralOrder(matrix);

    EXPECT_EQ(judge_same_vector(res, result), true);
}

TEST(path, common1)
{
    Solution solve;

    EXPECT_EQ(solve.uniquePaths(3, 2), 3);
    EXPECT_EQ(solve.uniquePaths(7, 3), 28);
    EXPECT_EQ(solve.uniquePaths(1, 2), 1);
    EXPECT_EQ(solve.uniquePaths(3, 3), 6);
    EXPECT_EQ(solve.uniquePaths(51, 9), 1916797311);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}