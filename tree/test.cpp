#include <gtest/gtest.h>
#include "tree.h"

// test cases
TEST(compare, common1)
{
    Matrix mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    EXPECT_EQ(mat1, mat2);
}

TEST(compare, common2)
{  
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {5, 4, 3, 2, 1};

    EXPECT_EQ(judge_same_vector(vec1, vec2), true);
}

TEST(genAndPrintTree, common1)
{
    Solution solve;

    vector<int> vec = {4, 2, 6, 3, 1, 5, -1};
    TreeNode *root = solve.createTree(vec, 0);
    solve.printBT("", root, false);
}

TEST(addOneRow, common1)
{
    Solution solve;

    vector<int> vec = {4, 2, 6, 3, 1, 5, -1};
    TreeNode *root = solve.createTree(vec, 0);
    solve.printBT("", root, false);
    TreeNode *res = solve.addOneRow(root, 1, 2);
    solve.printBT("", res, false);
}

TEST(addOneRow, common2)
{
    Solution solve;

    vector<int> vec = {4, 2, -1, 3, 1, -1, -1};
    TreeNode *root = solve.createTree(vec, 0);
    solve.printBT("", root, false);
    TreeNode *res = solve.addOneRow(root, 1, 3);
    solve.printBT("", res, false);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}