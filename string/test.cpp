#include <gtest/gtest.h>
#include "string.h"

TEST(Add, basic)
{
    Solution solve;

    EXPECT_EQ(solve.add(1, 2), 3);
}

TEST(print_vec, common1)
{
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<string> vec2 = {"lyc", "zzh", "xsl", "wzh"};

    print_vec<int>(vec1);
    print_vec<string>(vec2);
}

TEST(unique, common1)
{
    Solution solve;
    string str1 = "lyc";
    string str2 = "abcdea";
    
    EXPECT_EQ(solve.isUnique(str1, 0, str1.length()), true);
    EXPECT_EQ(solve.isUnique(str2, 0, str2.length()), false);
}

TEST(largestSubString, common1)
{
    Solution solve;
    string str1 = "abcabcbb";
    string str2 = "bbbbbbb";

    EXPECT_EQ(solve.lengthOfLongestSubstring1(str1), 3);
    EXPECT_EQ(solve.lengthOfLongestSubstring1(str2), 1);
}

TEST(largestSubString2, common1)
{
    Solution solve;
    string str1 = "abcabcbb";
    string str2 = "bbbbbbb";

    EXPECT_EQ(solve.lengthOfLongestSubstring2(str1), 3);
    EXPECT_EQ(solve.lengthOfLongestSubstring2(str2), 1);
}

TEST(largestSubString3, common1)
{
    Solution solve;
    string str1 = "abcabcbb";
    string str2 = "bbbbbbb";

    EXPECT_EQ(solve.lengthOfLongestSubstring3(str1), 3);
    EXPECT_EQ(solve.lengthOfLongestSubstring3(str2), 1);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}