#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int lengthOfLongestSubstring1(string s) 
    {
        // 暴力枚举法
        if (s.length() == 0 || s.length() == 1)
            return s.length();

        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + 1; j <= s.length(); j++)
            {
                if (isUnique(s, i, j) == true)
                    ans = max(ans, j - i);
            }
        }

        return ans;
    }

    int lengthOfLongestSubstring2(string s) 
    {
        // 滑动窗口法
        int left = 0, right = 0, ans = 0;
        set<char> mySet;
        pair<set<char>::iterator, bool> ret;
        int n = s.length();

        while (left < n && right < n)
        {
            ret = mySet.insert(s[right]);
            if (ret.second == true)
            {
                right++;
                ans = max(ans, right - left);
            }
            else
            {
                mySet.erase(s[left]);
                left++;
            }
        }

        return ans;
    }

    int lengthOfLongestSubstring3(string s) 
    {
        // 优化后的滑动窗口
        int n = s.length();
        map<char, int> myMap;
        int ans = 0;

        for (int left = 0, right = 0; right < n; right++)
        {
            if (myMap.find(s[right]) != myMap.end())
            {
                left = max(left, myMap[s[right]]);
                myMap.erase(s[right]);
            }
            ans = max(ans, right - left + 1);
            myMap.insert(pair<char, int>(s[right], right + 1));
        }

        return ans;
    }

    bool validPalindromic(string s, int left, int right)
    {
        for (; left < right; left++, right--)
        {
            if (s[left] != s[right])
                return false;
        }

        return true;
    }

    string longestPalindrome1(string s) 
    {
        // 暴力解法
        int len = s.length();
        if (len <= 1)
            return s;
        
        int maxLen = 1;
        int begin = 0;
        // 枚举所有子串
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (j - i + 1 > maxLen && validPalindromic(s, i, j) == true)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }

    int expandFromCenter(string s, int left, int right)
    {
        int len = s.length();
        int i = left;
        int j = right;

        while (i >= 0 && j < len)
        {
            if (s[i] == s[j])
            {
                i--;
                j++;
            }
            else
            {
                break;
            }
        }

        return j - i -1;
    }

    string longestPalindrome2(string s) 
    {
        // 中心扩散法，枚举中心
        int len = s.length();
        if (len <= 1)
            return s;

        int begin = 0, maxLen = 1;
        for (int i = 0; i < len - 1; i++)
        {
            int oddLen = expandFromCenter(s, i, i);
            int evenLen = expandFromCenter(s, i, i + 1);

            int curMaxLen = max(oddLen, evenLen);
            if (curMaxLen > maxLen)
            {
                maxLen = curMaxLen;
                begin = i - (maxLen - 1) / 2;
            }
        }

        return s.substr(begin, maxLen);
    }

    bool isUnique(string s, int start, int end)
    {   // 判断字符串中有没有重复的字符
        set<char> mySet;
        pair<set<char>::iterator, bool> ret;

        for (int i = start; i < end; i++)
        {
            ret = mySet.insert(s[i]);
            if (ret.second == false)
                return false;
        }

        return true;
    }

    using Matrix = vector<vector<bool>>;

    string longestPalindrome3(string s) 
    {
        // dynmaic programming
        int len = s.length();
        if (len <= 1)
            return s;

        int begin = 0, maxLen = 1;
        Matrix dp(len, vector<bool>(len, false));

        for (int i = 0; i < len - 1; i++)
        {
            dp[i][i] = true;
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                begin = i;
                maxLen = 2;
            }
        }

        dp[len - 1][len - 1] = true;
        // 每一列从小到大填表
        for (int column = 2; column < len; column++)
        {
            for (int row = 0; row < column - 1; row++)
            {
                if (dp[row + 1][column - 1] == true && s[row] == s[column])
                    dp[row][column] = true;
                
                if (dp[row][column] == true && column - row + 1 > maxLen)
                {
                    maxLen = column - row + 1;
                    begin = row;
                }
            }
        }


        return s.substr(begin, maxLen);
    }

    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0)
        {
            return "";
        }

        int shortLen = strs[0].length();
        for (auto it = strs.begin() + 1; it != strs.end(); it++)
        {
            shortLen = min((int)(*it).length(), shortLen);
        }

        string result = "";
        bool flag = true;
        for (int i = 0; i < shortLen; i++)
        {
            char tmp = strs[0][i];
            for (auto it = strs.begin() + 1; it != strs.end(); it++)
            {  
                if (tmp != (*it)[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                result += tmp;
            else
                break;
        }

        return result;
    }

    string convert(string s, int numRows) 
    {
        if (numRows <= 1)
            return s;
        if (s.length() <= numRows)
            return s;
        
        string result(s.length(), ' ');
        int k = numRows * 2 - 2;
        int a = 0;
        
        for (int j = 0; j < numRows; j++)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (i % k == j || i % k == k - j)
                    result[a++] = s[i];
            }
        } 

        return result;
    }
        
    vector<string> append (vector<char>& tmp, vector<string>& tempRes) 
    {   // tempRes为当前结果，tmp为追加的字符
        vector<string> res;
        int TO = max ((int)tempRes.size(), 1);

        for (int i = 0; i < TO; ++i) {
            for (int j = 0; j < tmp.size(); ++j) {
                string t = (tempRes.size() > 0) ? tempRes[i] : "";
                res.push_back (string(t + tmp[j]));
            }
        }
        
        return res;
    }

    vector<string> letterCombinations(string digits) 
    {
        vector<string> toLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;

        for (int i = 0; i < digits.length(); ++i) {
            string letters = toLetters[digits[i] - '0'];
            vector<char> currentLetters(begin(letters), end(letters));
            res = append(currentLetters, res); // append each currentLetters item to each res item
        }

        return res;
    }

    bool isMatch(string s, string p) 
    {
        // recursive
        if (p.size() == 0)
            return s.size() == 0;
        bool firstMatch = (s.size() != 0 && (p[0] == s[0] || p[0] == '.'));

        if (p.length() >= 2 && p[1] == '*')
        {
            return isMatch(s, p.substr(2, p.length() - 2)) || (firstMatch && isMatch(s.substr(1, s.length() - 1), p));
        }
        else
        {
            return firstMatch && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        }
    }

    bool isValid(string &s) 
    {
        std::stack<char> temp;

        for (const char i : s) 
        {
            if (i == '(' || i == '[' || i == '{') {
                temp.push(i);
                continue;
            }
            if (i == ')')
                if (temp.size() == 0 || temp.top() != '(')
                    return false;
                else
                    temp.pop();
            if (i == ']')
                if (temp.size() == 0 || temp.top() != '[')
                    return false;
                else
                    temp.pop();
            if (i == '}')
                if (temp.size() == 0 || temp.top() != '{')
                    return false;
                else
                    temp.pop();
        }
        
        return temp.size() == 0;
    }
};

ostream& operator<<(ostream &os, vector<int> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << "  ";
    }

    return os;
}

void print_vec_int(const vector<int> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

template<typename type>
void print_vec(vector<type> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
}

bool judge_same_vector(vector<int> &vec1, vector<int> &vec2)
{
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    if (vec1 == vec2)
        return true;
    else
        return false;
}

bool judge_same_multi_vector(vector<vector<int>> &vec1, vector<vector<int>> &vec2)
{
    vector<vector<int>>::iterator it1 = vec1.begin();
    for(; it1!=vec1.end(); it1++)
    {
        sort((*it1).begin(), (*it1).end());
    }

    vector<vector<int>>::iterator it2 = vec2.begin();
    for(; it2!=vec2.end(); it2++)
    {
        sort((*it2).begin(), (*it2).end());
    }

    it1 = vec1.begin();
    it2 = vec2.begin();
    while(it1 != vec1.end())
    {
        if (*it1 != *it2)
        {
            return false;
        }
        it1++;
        it2++;
    }

    return true;
}