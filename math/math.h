#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int add(int a, int b)
    {
        return a+b;
    }

    int reverse(int x) 
    {
        int ans = 0, copy = abs(x);

        while (copy > 0) 
        {
            if (INT32_MAX / 10 < ans) 
                return 0;  // check overflow
            ans = ans * 10 + copy % 10;
            copy /= 10;
        }

        return x < 0 ? -ans : ans;
    }

    // very important
    int myAtoi(string s) 
    {
        if (s.size() == 0)
            return 0;

        int i = 0;
        while (s[i] == ' ')
            ++i;

        int flag = 1;
        if (s[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if (isalpha(s[i]))
            return 0;
        
        int result = 0;
        while (i < s.size() && isdigit(s[i]))
        {
            if (flag > 0)
            {
                if (INT32_MAX / 10 < result)
                    return INT32_MAX;
                if (INT32_MAX / 10 == result)
                {
                    if ((s[i] - '0') > 7)
                        return INT32_MAX;
                }
                result = result * 10 + (s[i] - '0');
            }
            else if (flag < 0)
            {
                if (INT32_MIN / 10 > result)
                    return INT32_MIN;
                if (INT32_MIN / 10 == result)
                {
                    if ((s[i] - '0') > 8)
                        return INT32_MIN;
                }
                result = result * 10 - (s[i] - '0');
            }

            ++i;
        }

        return result;
    }

    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;
        if (x == 0 || (x / 10) == 0)
            return true;
        
        long rev = 0;
        int copy = x;
        while (x != 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        if (rev == copy)
            return true;
        return false;
    }

    void print_vec(vector<int> &vec)
    {
        vector<int>::iterator it = vec.begin();
        for ( ; it != vec.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};

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