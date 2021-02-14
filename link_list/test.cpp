#include <gtest/gtest.h>
#include "LinkList.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(print, basic)
{
    // cout can be seen
    // cout << "I am here" << endl; 
}

TEST(judgeLinkList, basic)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {1, 2, 3, 4, 5};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);

    EXPECT_EQ(judge_same_linklist(l1, l2), true);
}

TEST(judgeLinkList, basic2)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);

    EXPECT_EQ(judge_same_linklist(l1, l2), false);
}

TEST(judgeLinkList, basic3)
{
    Solution solve;
    vector<int> vec1 = {1};
    vector<int> vec2 = {1};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);

    EXPECT_EQ(judge_same_linklist(l1, l2), true);
}

TEST(judgeLinkList, empty1)
{
    Solution solve;
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;

    EXPECT_EQ(judge_same_linklist(l1, l2), true);
}

TEST(judgeLinkList, empty2)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    ListNode *l1 = nullptr;
    ListNode *l2 = solve.init_linklist_vec(vec1);

    EXPECT_EQ(judge_same_linklist(l1, l2), false);
}

TEST(remove, common1)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> res1 = {1, 2, 3, 5};
    ListNode *in = solve.init_linklist_vec(vec1);
    ListNode *out = solve.init_linklist_vec(res1);

    //solve.print_LinkList(solve.removeNthFromEnd(in, 2));

    EXPECT_EQ(judge_same_linklist(solve.removeNthFromEnd(in, 2), out), true);
}

TEST(remove, common2)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> res1 = {1, 2, 3, 4};
    ListNode *in = solve.init_linklist_vec(vec1);
    ListNode *out = solve.init_linklist_vec(res1);

    // solve.print_LinkList(solve.removeNthFromEnd(in, 2));

    EXPECT_EQ(judge_same_linklist(solve.removeNthFromEnd(in, 1), out), true);
}

TEST(remove, limit1)
{
    Solution solve;
    vector<int> vec1 = {1};
    vector<int> res1 = {};
    ListNode *in = solve.init_linklist_vec(vec1);
    ListNode *out = solve.init_linklist_vec(res1);

    //solve.print_LinkList(solve.removeNthFromEnd(in, 2));

    EXPECT_EQ(judge_same_linklist(solve.removeNthFromEnd(in, 1), out), true);
}

TEST(remove, limit2)
{
    Solution solve;
    vector<int> vec1 = {1, 2};
    vector<int> res1 = {1};
    ListNode *in = solve.init_linklist_vec(vec1);
    ListNode *out = solve.init_linklist_vec(res1);

    //solve.print_LinkList(solve.removeNthFromEnd(in, 2));

    EXPECT_EQ(judge_same_linklist(solve.removeNthFromEnd(in, 1), out), true);
}

TEST(remove, limit3)
{
    Solution solve;
    vector<int> vec1 = {1, 2};
    vector<int> res1 = {2};
    ListNode *in = solve.init_linklist_vec(vec1);
    ListNode *out = solve.init_linklist_vec(res1);

    //solve.print_LinkList(solve.removeNthFromEnd(in, 2));

    EXPECT_EQ(judge_same_linklist(solve.removeNthFromEnd(in, 2), out), true);
}

TEST(merge, common1)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 4};
    vector<int> vec2 = {1, 3, 4};
    vector<int> res = {1, 1, 2, 3, 4, 4};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);
    ListNode *result = solve.init_linklist_vec(res);

    EXPECT_EQ(judge_same_linklist(solve.mergeTwoLists(l1, l2), result), true);
}

TEST(merge, common2)
{
    Solution solve;
    vector<int> vec1 = {1, 2, 4, 5, 6};
    vector<int> vec2 = {1, 3, 4};
    vector<int> res = {1, 1, 2, 3, 4, 4, 5, 6};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);
    ListNode *result = solve.init_linklist_vec(res);

    EXPECT_EQ(judge_same_linklist(solve.mergeTwoLists(l1, l2), result), true);
}

TEST(merge, empty1)
{
    Solution solve;
    vector<int> vec1 = {};
    vector<int> vec2 = {};
    vector<int> res = {};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);
    ListNode *result = solve.init_linklist_vec(res);

    EXPECT_EQ(judge_same_linklist(solve.mergeTwoLists(l1, l2), result), true);
}

TEST(merge, empty2)
{
    Solution solve;
    vector<int> vec1 = {};
    vector<int> vec2 = {1};
    vector<int> res = {1};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);
    ListNode *result = solve.init_linklist_vec(res);

    EXPECT_EQ(judge_same_linklist(solve.mergeTwoLists(l1, l2), result), true);
}

TEST(multiMerge, common1)
{
    Solution solve;
    vector<int> vec1 = {1, 4, 5};
    vector<int> vec2 = {1, 3, 4};
    vector<int> vec3 = {2, 6};
    vector<int> res = {1, 1, 2, 3, 4, 4, 5, 6};
    ListNode *l1 = solve.init_linklist_vec(vec1);
    ListNode *l2 = solve.init_linklist_vec(vec2);
    ListNode *l3 = solve.init_linklist_vec(vec3);
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode *result = solve.init_linklist_vec(res);
    
    EXPECT_EQ(judge_same_linklist(solve.mergeKLists(lists), result), true);
}

TEST(multimerge, limit1)
{
    Solution solve;
    vector<ListNode*> lists = {};
    ListNode *result = nullptr;

    EXPECT_EQ(judge_same_linklist(solve.mergeKLists(lists), result), true);
}

TEST(exchange, common1)
{
    Solution solve;
    vector<int> vec = {1, 2, 3, 4};
    vector<int> res = {2, 1, 4, 3};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    //solve.print_LinkList(solve.swapPairs(list));
    EXPECT_EQ(judge_same_linklist(solve.swapPairs(list), result), true);
}

TEST(exchange, common2)
{
    Solution solve;
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    vector<int> res = {2, 1, 4, 3, 6, 5};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    //solve.print_LinkList(solve.swapPairs(list));
    EXPECT_EQ(judge_same_linklist(solve.swapPairs(list), result), true);
}

TEST(exchange, common3)
{
    Solution solve;
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> res = {2, 1, 4, 3, 5};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    //solve.print_LinkList(solve.swapPairs(list));
    EXPECT_EQ(judge_same_linklist(solve.swapPairs(list), result), true);
}

TEST(exchange, limit1)
{
    Solution solve;
    vector<int> vec = {1};
    vector<int> res = {1};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    //solve.print_LinkList(solve.swapPairs(list));
    EXPECT_EQ(judge_same_linklist(solve.swapPairs(list), result), true);
}

TEST(exchange, limit2)
{
    Solution solve;
    vector<int> vec = {};
    vector<int> res = {};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    //solve.print_LinkList(solve.swapPairs(list));
    EXPECT_EQ(judge_same_linklist(solve.swapPairs(list), result), true);
}

TEST(rotate, common1)
{
    Solution solve;
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> res = {4, 5, 1, 2, 3};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    // solve.print_LinkList(solve.rotateRight(list, 2));
    EXPECT_EQ(judge_same_linklist(solve.rotateRight(list, 2), result), true);
}

TEST(rotate, common2)
{
    Solution solve;
    vector<int> vec = {0, 1, 2};
    vector<int> res = {2, 0, 1};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    // solve.print_LinkList(solve.rotateRight(list, 4));
    EXPECT_EQ(judge_same_linklist(solve.rotateRight(list, 4), result), true);
}

TEST(rotate, common3)
{
    Solution solve;
    vector<int> vec = {0, 1, 2};
    vector<int> res = {2, 0, 1};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    // solve.print_LinkList(solve.rotateRight(list, 4));
    EXPECT_EQ(judge_same_linklist(solve.rotateRight(list, 1), result), true);
}

TEST(rotate, common4)
{
    Solution solve;
    vector<int> vec = {0, 1, 2};
    vector<int> res = {1, 2, 0};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    // solve.print_LinkList(solve.rotateRight(list, 4));
    EXPECT_EQ(judge_same_linklist(solve.rotateRight(list, 2), result), true);
}

TEST(rotate, common5)
{
    Solution solve;
    vector<int> vec = {0, 1, 2};
    vector<int> res = {0, 1, 2};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    // solve.print_LinkList(solve.rotateRight(list, 4));
    EXPECT_EQ(judge_same_linklist(solve.rotateRight(list, 3), result), true);
}

TEST(deleteSortList, common1)
{
    Solution solve;
    vector<int> vec = {1, 1, 2, 2, 3, 3, 3, 4, 5};
    vector<int> res = {1, 2, 3, 4, 5};
    ListNode *list = solve.init_linklist_vec(vec);
    ListNode *result = solve.init_linklist_vec(res);

    // solve.print_LinkList(solve.rotateRight(list, 4));
    EXPECT_EQ(judge_same_linklist(solve.deleteDuplicates(list), result), true);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}