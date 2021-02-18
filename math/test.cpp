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

TEST(romaN1, common1)
{
    Solution solve;

    EXPECT_EQ(solve.romanToInt("III"), 3);
    EXPECT_EQ(solve.romanToInt("IV"), 4);
    EXPECT_EQ(solve.romanToInt("IX"), 9);
    EXPECT_EQ(solve.romanToInt("LVIII"), 58);
    EXPECT_EQ(solve.romanToInt("MCMXCIV"), 1994);
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

TEST(roman2, common1)
{
    Solution solve;

    EXPECT_EQ(solve.intToRoman(3), "III");
    EXPECT_EQ(solve.intToRoman(4), "IV");
    EXPECT_EQ(solve.intToRoman(9), "IX");
    EXPECT_EQ(solve.intToRoman(58), "LVIII");
    EXPECT_EQ(solve.intToRoman(1994), "MCMXCIV");
}

TEST(divide, common1)
{
    Solution solve;

    EXPECT_EQ(solve.divide(10, 3), 3);
    EXPECT_EQ(solve.divide(7, -3), -2);
    EXPECT_EQ(solve.divide(0, 1), 0);
    EXPECT_EQ(solve.divide(1, 1), 1);
    EXPECT_EQ(solve.divide(20, 3), 6);
    EXPECT_EQ(solve.divide(-2147483648, 1), -2147483648);
    // EXPECT_EQ(solve.divide(2147483649, 1), 2147483649);
}

TEST(multiplyStr, common1)
{
    Solution solve;

    //EXPECT_EQ(solve.multiply("123", "123"), "15129");
    //EXPECT_EQ(solve.multiply("1", "1"), "1");
    //EXPECT_EQ(solve.multiply("123", "456"), "56088");
    //EXPECT_EQ(solve.multiply("9", "9"), "81");
    EXPECT_EQ(solve.multiply("9", "99"), "891");
    EXPECT_EQ(solve.multiply("0", "99999"), "0");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}