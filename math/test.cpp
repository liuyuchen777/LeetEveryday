#include <gtest/gtest.h>
#include "math.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(reverse, common1)
{
    Solution solve;

    EXPECT_EQ(solve.reverse(0), 0);
    EXPECT_EQ(solve.reverse(123), 321);
    EXPECT_EQ(solve.reverse(-123), -321);
    EXPECT_EQ(solve.reverse(120), 21);
}

TEST(palinrome, common1)
{
    Solution solve;

    EXPECT_EQ(solve.isPalindrome(121), true);
    EXPECT_EQ(solve.isPalindrome(-121), false);
    EXPECT_EQ(solve.isPalindrome(10), false);
    EXPECT_EQ(solve.isPalindrome(0), true);
    EXPECT_EQ(solve.isPalindrome(7), true);
}

TEST(atoi, common1)
{
    Solution solve;
    string str1 = "321";
    string str2= "0";
    string str3 = "    -42";
    string str4 = "42";
    string str5 = "4193 string";
    string str6 = "word 282828";
    string str7 = "-91283472332";
    string str8 = "2147483648";

    EXPECT_EQ(solve.myAtoi(str1), 321);
    EXPECT_EQ(solve.myAtoi(str2), 0);
    EXPECT_EQ(solve.myAtoi(str3), -42);
    EXPECT_EQ(solve.myAtoi(str4), 42);
    EXPECT_EQ(solve.myAtoi(str5), 4193);
    EXPECT_EQ(solve.myAtoi(str6), 0);
    EXPECT_EQ(solve.myAtoi(str7), INT32_MIN);
    EXPECT_EQ(solve.myAtoi(str8), INT32_MAX);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}