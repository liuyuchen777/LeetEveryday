#include <gtest/gtest.h>
#include "sortPro.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(merge, common1)
{
    Solution solve;
    using myType = std::vector<vector<int>>;
    myType vec = {{1,3}, {2, 6}, {8, 10}, {15, 18}};
    myType res = solve.merge(vec);
    myType result = {{1, 6}, {8, 10}, {15, 18}};

    EXPECT_EQ(judge_same_multi_vector(res, result), true);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}