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

    using Interval = std::vector<int>;

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(),
            [](const Interval &a, const Interval &b){
                return a[0] < b[0];
            }
        );
        
        result.push_back(intervals.front());

        for (int i = 0; i < intervals.size(); i++)
        {
            auto &res_end = result.back()[1];
            if(res_end < intervals[i][0])
                result.push_back(intervals[i]);
            else
                res_end = max(res_end, intervals[i][1]);
        }
        
        return result;
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