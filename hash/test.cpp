#include <gtest/gtest.h>
#include "hash.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

/*
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

    list.insert(3, 10);
    list.print();
}

TEST(LinkList, insert4)
{
    vector<int> vec = {1};
    LinkList list(vec);

    list.insert(1, 10);
    list.print();
}

TEST(LinkList, insert5)
{
    LinkList list;

    list.insert(1, 10);
    list.print();
}

TEST(LinkList, erase1)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    LinkList list(vec);

    list.erase();
    list.print();
}

TEST(LinkList, erase2)
{
    vector<int> vec;
    LinkList list(vec);

    if (list.erase() == -1)
        cout << "Invalid Erase!" << endl;
    list.print();
}

TEST(LinkList, erase3)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    LinkList list(vec);

    list.erase(2);
    list.print();
}
*/

// test cases
TEST(single, common1)
{
    Solution solve;
    vector<int> vec1 = {2, 2, 1};

    EXPECT_EQ(solve.singleNumber(vec1), 1);
}

TEST(single2, common1)
{
    Solution solve;
    vector<int> vec1 = {2, 2, 1};

    EXPECT_EQ(solve.singleNumber2(vec1), 1);
}

TEST(prime, common1)
{
    Solution solve;

    EXPECT_EQ(solve.isPrime(2), true);
    EXPECT_EQ(solve.isPrime(7), true);
    EXPECT_EQ(solve.isPrime(13), true);
    EXPECT_EQ(solve.isPrime(4), false);
}

TEST(manyPrime, common1)
{
    Solution solve;

    EXPECT_EQ(solve.countPrimes(10), 4);
    EXPECT_EQ(solve.countPrimes(0), 0);
    EXPECT_EQ(solve.countPrimes(1), 0);
}

TEST(count, common1)
{
    Solution solve;

    EXPECT_EQ(solve.countPrimes2(10), 4);
    EXPECT_EQ(solve.countPrimes2(2), 0);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}