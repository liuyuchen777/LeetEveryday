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

TEST(Palindrome, common1)
{
    Solution solve;
    string str1 = "ababcc";

    EXPECT_EQ(solve.longestPalindrome1(str1), "aba");
}

TEST(Palindrome, common2)
{
    Solution solve;
    string str1 = "cbbd";

    EXPECT_EQ(solve.longestPalindrome1(str1), "bb");
}

TEST(Palindrome2, common1)
{
    Solution solve;
    string str1 = "cbbd";

    EXPECT_EQ(solve.longestPalindrome2(str1), "bb");
}

TEST(Palindrome2, common2)
{
    Solution solve;
    string str1 = "abacad";

    EXPECT_EQ(solve.longestPalindrome2(str1), "aba");
}

TEST(Palindrome2, common3)
{
    Solution solve;
    string str1 = "bb";

    EXPECT_EQ(solve.longestPalindrome2(str1), "bb");
}

TEST(Palindrome3, common1)
{
    Solution solve;
    string str1 = "abacad";

    EXPECT_EQ(solve.longestPalindrome3(str1), "aba");
}

TEST(Palindrome3, common2)
{
    Solution solve;
    string str1 = "bbbbbb";

    EXPECT_EQ(solve.longestPalindrome3(str1), "bbbbbb");
}

TEST(prefix, common1)
{
    Solution solve;
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {};

    EXPECT_EQ(solve.longestCommonPrefix(strs1), "fl");
    EXPECT_EQ(solve.longestCommonPrefix(strs2), "");
    EXPECT_EQ(solve.longestCommonPrefix(strs3), "");
}

TEST(ZigZag, common1)
{
    Solution solve;
    string str1 = "PAYPALISHIRING";
    string str2 = "PAYPALISHIRING";
    string res1 = "PAHNAPLSIIGYIR";
    string res2 = "PINALSIGYAHRPI";

    EXPECT_EQ(solve.convert(str1, 3), res1);
    EXPECT_EQ(solve.convert(str2, 4), res2);
}

TEST(match, common1)
{
    Solution solve;
    
    string s1 = "aa";
    string p1 = "a*";

    string s2 = "aa";
    string p2 = "a";

    string s3 = "aab";
    string p3 = "c*a*b";

    EXPECT_EQ(solve.isMatch(s1, p1), true);
    EXPECT_EQ(solve.isMatch(s2, p2), false);
    EXPECT_EQ(solve.isMatch(s3, p3), true);
}

TEST(valid, common1)
{
    Solution solve;

    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";

    EXPECT_EQ(solve.isValid(s1), true);
    EXPECT_EQ(solve.isValid(s2), true);
    EXPECT_EQ(solve.isValid(s3), false);
}

TEST(gen, common1)
{
    Solution solve;

    vector<string> result = solve.generateParenthesis(3);

    print_vec(result);
}

TEST(gen2, common1)
{
    Solution solve;

    vector<string> result = solve.generateParenthesis2(3);

    print_vec(result);
}

TEST(remove, common1)
{
    Solution solve;

    vector<int> vec1 = {3, 2, 2, 3};
    vector<int> vec2 = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> vec3;

    EXPECT_EQ(solve.removeElement(vec1, 3), 2);
    EXPECT_EQ(solve.removeElement(vec2, 2), 5);
    EXPECT_EQ(solve.removeElement(vec3, 5), 0);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}