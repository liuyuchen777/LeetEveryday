#include <gtest/gtest.h>
#include "stack.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

// test cases
/*
TEST(slice, common1)
{
    Solution solve;
    string str = "/home/lyc/go/src";
    vector<string> vec = solve.split(str, "/");

    print_vec(vec);
}
/*

/*
TEST(path, common1)
{
    Solution solve;
    string str = "/home/../home/go";
    vector<string> vec = solve.simplifyPath(str);

    cout << "*******************" << endl;
    print_vec(vec);
}
*/

TEST(path, common1)
{
    Solution solve;
    string str1 = "/home/../home/go/";
    string str2 = "/home/";
    string str3 = "/a/./b/../../c/";
    string str4 = "/../";
    string str5 = "/a//b////c/d//././/..";
    
    EXPECT_EQ(solve.simplifyPath(str1), "/home/go");
    EXPECT_EQ(solve.simplifyPath(str2), "/home");
    EXPECT_EQ(solve.simplifyPath(str3), "/c");
    EXPECT_EQ(solve.simplifyPath(str4), "/");
    EXPECT_EQ(solve.simplifyPath(str5), "/a/b/c");
}

TEST(path3, common1)
{
    Solution solve;
    string str1 = "/home/../home/go/";
    string str2 = "/home/";
    string str3 = "/a/./b/../../c/";
    string str4 = "/../";
    string str5 = "/a//b////c/d//././/..";
    
    EXPECT_EQ(solve.simplifyPath3(str1), "/home/go");
    EXPECT_EQ(solve.simplifyPath3(str2), "/home");
    EXPECT_EQ(solve.simplifyPath3(str3), "/c");
    EXPECT_EQ(solve.simplifyPath3(str4), "/");
    EXPECT_EQ(solve.simplifyPath3(str5), "/a/b/c");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}