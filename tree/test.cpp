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


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}