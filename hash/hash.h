#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

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

class Solution {
public:
    int add(int a, int b)
    {
        // test function
        return a + b;
    }

    // func
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // sort
        map<string, vector<string>> mpp;
    
        for(string str : strs)
        {
            string copy = str;
            sort(copy.begin(),copy.end());
            mpp[copy].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto x : mpp)
        {     
            ans.push_back(x.second);
        }

        return ans;
    }
    // 概念：哈希计数
    vector<vector<string>> groupAnagrams2(vector<string>& strs) 
    {
        // without sort
        map<map<char,int>,vector<string>>mpp;  
        for(string s : strs)
        {
            map<char,int>mpp2;
            for(char ch : s)
                mpp2[ch]++;
            mpp[mpp2].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x : mpp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }

    int singleNumber(vector<int>& nums) 
    {
        map<int, int> mpp;
        for (auto num : nums)
        {
            mpp[num]++;
        }
        for (auto key : mpp)
        {
            if (key.second == 1)
                return key.first;
        }
        return -1;
    }

    int singleNumber2(vector<int>& nums) 
    {
        int result = nums[0];
        
        for (auto it = nums.begin() + 1; it != nums.end(); it++)
            result ^= *it;

        return result;
    }

    bool isHappy(int n) 
    {
        unordered_set<int> us {n};

        while(n!=1) {
            int sum = 0;
            while(n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if(us.count(sum)) return false;
            us.insert(sum);
            n = sum;
        }

        return true;
    }

    bool isPrime(int num)
    {
        int div = 2;
        while (div != num)
        {
            if (num % div == 0)
                return false;
            div++;
        }
        return true;
    }

    int countPrimes(int n) 
    {
        // limit judge
        if (n <= 2)
            return 0;
        
        vector<int> primeSet = {2};
        int i = 2, count = 1;

        while(i < n)
        {
            if (i % 2 == 0)
            {
                i++;
                continue;
            }
            else
            {
                int flag = 0;
                for (auto it = primeSet.begin(); it != primeSet.end(); it++)
                {   
                    if ((i % (*it)) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    primeSet.push_back(i);
                    count++;
                }
                i++;
            }
        }

        return count;
    }

    int countPrimes2(int n)
    {
        if(n < 2)
            return 0;
        vector<bool> ans(n, true);
        for(int i = 2; i * i < n; i++)
        {
            if(ans[i] == true)
            {
                for(int j = i * i; j < n; j += i)
                {
                    ans[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(ans[i] == true)
                count++;
        }
        return count;
    } 
};