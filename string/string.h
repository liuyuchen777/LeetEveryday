#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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

    string longestPalindrome(string s) 
    {
        return "";
    }

    bool isUnique(string s, int start, int end)
    {
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
};

void print_vec_int(vector<int> &vec)
{
    for (auto it = vec.begin() ; it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename type>
void print_vec(vector<type> &vec)
{
    for (auto it = vec.begin() ; it != vec.end(); it++)
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