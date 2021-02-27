#include <gtest/gtest.h>
#include "array.h"

TEST(threeSumClose, common1)
{
    Solution solve;
    vector<int> array = {-1, 2, 1, -4};
    int target = 1;
    int ans = 2;

    EXPECT_EQ(solve.threeSumClosest(array, target), ans);
}

TEST(JudgeMUlti, common1)
{
    vector<vector<int>> array1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> array2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    EXPECT_EQ(judge_same_multi_vector(array1, array2), true);
}

TEST(SumupTest, basicfun1)
{
    Solution solve;

    vector<int> arr = {3, 3};
    int target = 6;
    vector<int> res = solve.twoSum(arr, target);

    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 1);
}

TEST(SumupTest, basicfun2)
{
    Solution solve;

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = solve.twoSum(arr, target);

    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 1);
}

TEST(SumupTest, empty1)
{
    Solution solve;

    vector<int> arr = {};
    int target = 9;
    vector<int> res = solve.twoSum(arr, target);

    EXPECT_EQ(res.size(), 0);
}

TEST(maxArea, common1)
{
    Solution solve;
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    EXPECT_EQ(solve.maxArea(arr), 49);
}

TEST(maxArea, common2)
{
    Solution solve;
    vector<int> arr = {1, 1};

    EXPECT_EQ(solve.maxArea(arr), 1);
}

TEST(maxArea, common3)
{
    Solution solve;
    vector<int> arr = {4, 3, 2, 1, 4};

    EXPECT_EQ(solve.maxArea(arr), 16);
}

TEST(maxArea, common4)
{
    Solution solve;
    vector<int> arr = {1, 2, 1};

    EXPECT_EQ(solve.maxArea(arr), 2);
}

TEST(maxArea, common5)
{
    Solution solve;
    vector<int> arr = {2, 3, 4, 5, 18, 17, 6};

    EXPECT_EQ(solve.maxArea(arr), 17);
}


TEST(threeSum, value1)
{
    Solution solve;
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = solve.threeSum(arr);
    vector<vector<int>> res = {{-1, -1, 2}, {-1, 0, 1}};

    vector<int> arr2 = {};
    vector<vector<int>> result2 = solve.threeSum(arr2);
    vector<vector<int>> res2 = {};
    
    EXPECT_EQ(judge_same_multi_vector(result, res), true);
    EXPECT_EQ(judge_same_multi_vector(result2, res2), true);
}


TEST(JudgeFun, simple1)
{
    vector<int> vec1 = {-1, -1, 0};
    vector<int> vec2 = {0, -1, -1};

    EXPECT_EQ(judge_same_vector(vec1, vec2), true);
}

TEST(merge, common1)
{
    Solution solve;
    vector<int> vec1 = {1, 3};
    vector<int> vec2 = {2};

    EXPECT_EQ(solve.findMedianSortedArrays(vec1, vec2), 2.0);
}

TEST(merge, common2)
{
    Solution solve;
    vector<int> vec1 = {1, 2};
    vector<int> vec2 = {3, 4};

    EXPECT_EQ(solve.findMedianSortedArrays(vec1, vec2), 2.5);
}

TEST(merge, common3)
{
    Solution solve;
    vector<int> vec1 = {0, 0};
    vector<int> vec2 = {0, 0};

    EXPECT_EQ(solve.findMedianSortedArrays(vec1, vec2), 0.0);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}