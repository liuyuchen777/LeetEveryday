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

TEST(reverse, common1)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vec2 = {1, 2, 3, 4, 5, 6};
    Solution solve;

    myReverse(vec.begin(), vec.end());
    cout << vec << endl;
    myReverse(vec2.begin(), vec2.end());
    cout << vec2 << endl;
}

TEST(next, common1)
{
    vector<int> vec1 = {5, 4, 3, 2, 1};
    vector<int> vec2 = {1, 2, 3};
    vector<int> vec3 = {1, 5, 8, 4, 7, 6, 5, 3, 1};
    vector<int> vec4 = {1, 3, 2};
    vector<int> vec5 = {1, 2};
    Solution solve;

    solve.nextPermutation(vec1);
    cout << vec1 << endl;
    solve.nextPermutation(vec2);
    cout << vec2 << endl;
    solve.nextPermutation(vec3);
    cout << vec3 << endl;
    solve.nextPermutation(vec4);
    cout << vec4 << endl;
    solve.nextPermutation(vec5);
    cout << vec5 << endl;
}

TEST(candy, common1)
{
    vector<int> vec1 = {1, 1, 2, 2, 3, 3};
    vector<int> vec2 = {1, 1, 2, 3};
    vector<int> vec3 = {6, 6, 6, 6};
    Solution solve;

    EXPECT_EQ(solve.distributeCandies(vec1), 3);
    EXPECT_EQ(solve.distributeCandies(vec2), 2);
    EXPECT_EQ(solve.distributeCandies(vec3), 1);
}

TEST(misMatch, common1)
{
    vector<int> vec1 = {1, 2, 2, 4};
    vector<int> res1 = {2, 3};
    vector<int> vec2 = {1, 2, 3, 3, 4, 6};
    vector<int> res2 = {3, 5};
    vector<int> vec3 = {1, 1};
    vector<int> res3 = {1, 2};
    vector<int> vec4 = {2, 2};
    vector<int> res4 = {2, 1};
    Solution solve;

    EXPECT_EQ(solve.findErrorNums(vec1), res1);
    EXPECT_EQ(solve.findErrorNums(vec2), res2);
    EXPECT_EQ(solve.findErrorNums(vec3), res3);
    EXPECT_EQ(solve.findErrorNums(vec4), res4);
}

TEST(miss, common1)
{
    Solution solve;

    vector<int> vec1 = {1, 2, 3, 4};

    solve.missingNumber(vec1);
}

TEST(search, common1)
{
    Solution solve;
    vector<int> vec1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> vec2 = {1};

    EXPECT_EQ(solve.search(vec1, 0), 4);
    EXPECT_EQ(solve.search(vec1, 3), -1);
    EXPECT_EQ(solve.search(vec2, 0), -1);
}

TEST(searchRange, common1)
{
    Solution solve;
    vector<int> vec1 = {5, 7, 7, 8, 8, 10};
    vector<int> res1 = {3, 4};
    vector<int> res2 = {-1, -1};
    vector<int> vec2 = {};
    vector<int> vec3 = {2, 2};
    vector<int> res3 = {0, 1};
    vector<int> vec4 = {1};
    vector<int> res4 = {0, 0};

    EXPECT_EQ(solve.searchRange(vec1, 8), res1);
    EXPECT_EQ(solve.searchRange(vec1, 6), res2);
    EXPECT_EQ(solve.searchRange(vec2, 0), res2);
    EXPECT_EQ(solve.searchRange(vec3, 2), res3);
    EXPECT_EQ(solve.searchRange(vec4, 1), res4);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}