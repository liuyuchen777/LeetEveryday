#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        int add(int a, int b)
        {
            // test function
            return a + b;
        }

        // func
        
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