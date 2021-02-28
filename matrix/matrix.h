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

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        if (matrix.size() == 0)
            return ans;

        int top = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        const int total_size = (down + 1) * (right + 1);

        while (ans.size()<total_size)
        {
            for (int j=left; j<=right && ans.size()<total_size; j++)
                ans.push_back(matrix[top][j]);
            top++;
            for (int i=top; i<=down && ans.size()<total_size; i++)
                ans.push_back(matrix[i][right]);
            right--;
            for (int j=right; j>=left && ans.size()<total_size; j--)
                ans.push_back(matrix[down][j]);
            down--;
            for (int i=down; i>=top && ans.size()<total_size; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }

        return ans;
    }

    int uniquePaths(int m, int n)
    {
        /*
        // recursive
        if (m == 1 && n == 1)
            return 1;
        if (m == 1 && n != 1)
            return uniquePaths(1, n - 1);
        if (m != 1 && n == 1)
            return uniquePaths(m - 1, 1);
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1); 
        */

        // dynamic programming
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(m==1 && n==1) return 1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 && j == 0) 
                    dp[i][j]==0;
                else if((i == 0 && j != 0)||(i != 0 && j == 0))
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    using Matrix = std::vector<vector<int>>;

    void rotate(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> v = matrix; 
        int k = 0;

        for(int i = v.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < v.size(); j++)
                matrix[j][k] = v[i][j];
            k++;
        }
    }

    void rotate2(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int tmp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 -i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - i - 1] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
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