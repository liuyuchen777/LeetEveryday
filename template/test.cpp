#include <gtest/gtest.h>
#include "xxx.h"
#include "LinkList.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(print_vec, common1)
{
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << vec << endl;
}

TEST(print_vec, common2)
{
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    print_vec(vec);
}

TEST(LinkList, common1)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    LinkList list(vec);

    list.print();
}

TEST(LinkList, end)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    LinkList list(vec);
    ListNode *end = list.end();

    cout << end->val << endl;
}

TEST(LinkList, insert1)
{
    LinkList list;

    list.insert(1);
    list.insert(2);
    list.print();
}

TEST(LinkList, insert2)
{
    LinkList list;

    ListNode *node = new ListNode(20);
    list.insert(node);
    ListNode *node2 = new ListNode(30);
    list.insert(node2);
    list.print();
}

TEST(LinkList, insert3)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    LinkList list(vec);

    
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}