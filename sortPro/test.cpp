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

TEST(insert, limit)
{
    Solution solve;
    using myType = std::vector<vector<int>>;

    myType vec1;
    vector<int> new1 = {2, 5};
    myType res1 = solve.insert(vec1, new1);
    myType result1 = {{2, 5}};
    EXPECT_EQ(judge_same_multi_vector(res1, result1), true);

    myType vec2 = {{4, 5}, {7, 8}, {9, 10}};
    vector<int> new2 = {1, 2};
    myType res2 = solve.insert(vec2, new2);
    myType result2 = {{1, 2}, {4, 5}, {7, 8}, {9, 10}};
    EXPECT_EQ(judge_same_multi_vector(res2, result2), true);
    
    myType vec3 = {{4, 5}, {7, 8}, {9, 10}};
    vector<int> new3 = {13, 16};
    myType res3 = solve.insert(vec3, new3);
    myType result3 = {{4, 5}, {7, 8}, {9, 10}, {13, 16}};
    EXPECT_EQ(judge_same_multi_vector(res3, result3), true);
}

TEST(insert, common1)
{
    Solution solve;
    using myType = std::vector<vector<int>>;

    myType vec1 = {{1, 3}, {6, 9}};
    vector<int> new1 = {2, 5};
    myType res1 = solve.insert(vec1, new1);
    myType result1 = {{1, 5}, {6, 9}};
    EXPECT_EQ(judge_same_multi_vector(res1, result1), true);
}

TEST(insert2, common1)
{
    Solution solve;
    using myType = std::vector<vector<int>>;

    myType vec1 = {{1, 3}, {6, 9}};
    vector<int> new1 = {2, 5};
    myType res1 = solve.insert2(vec1, new1);
    myType result1 = {{1, 5}, {6, 9}};
    EXPECT_EQ(judge_same_multi_vector(res1, result1), true);
}

TEST(insertionSortList, common1)
{
    Solution solve;

    vector<int> vec1 = {5, 2, 3, 1, 4};
    vector<int> vec2 = {1, 2, 3, 4, 5};
    ListNode *list = solve.init_linklist_vec(vec1);
    ListNode *result = solve.init_linklist_vec(vec2);
    ListNode *res = solve.insertionSortList(list);

    EXPECT_EQ(judge_same_linklist(result, res), true);
}

TEST(insertionSortList, common2)
{
    Solution solve;

    vector<int> vec1 = {-1, 5, 3, 4, 0};
    vector<int> vec2 = {-1, 0, 3, 4, 5};
    ListNode *list = solve.init_linklist_vec(vec1);
    ListNode *result = solve.init_linklist_vec(vec2);
    ListNode *res = solve.insertionSortList(list);

    EXPECT_EQ(judge_same_linklist(result, res), true);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}