#include <gtest/gtest.h>
#include "offer.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(mSearch, commo1)
{
    Solution solve;

    Matrix mat = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    EXPECT_EQ(solve.matrixSearch(mat, 9), true);
    EXPECT_EQ(solve.matrixSearch(mat, 22), false);
}

/*
TEST(string, common1)
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    char *str3 = "hello world";
    char *str4 = "hello world";

    if (str1 == str2)
        cout << "str1 and str2 are same!" << endl;
    else
        cout << "str1 and str2 are not same!" << endl;
    
    if (str3 == str4)
        cout << "str3 and str4 are same!" << endl;
    else
        cout << "str3 and str4 are not same!" << endl;
}
*/

TEST(replace, common1)
{
    Solution solve;
    string str = "I am King!";
    string res = solve.replaceSpace(str);
    string result = "I%20am%20King!";

    EXPECT_EQ(res, result);
}

TEST(replace, limit1)
{
    Solution solve;
    string str = "";
    string res = solve.replaceSpace(str);
    string result = "";
    
    EXPECT_EQ(res, result);
}

TEST(replace, limit2)
{
    Solution solve;
    string str = "   ";
    string res = solve.replaceSpace(str);
    string result = "%20%20%20";
    
    EXPECT_EQ(res, result);
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}