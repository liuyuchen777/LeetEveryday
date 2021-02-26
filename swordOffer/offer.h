#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using Matrix = std::vector<vector<int>>;

class Solution {
public:
    int add(int a, int b)
    {
        return a+b;
    }

    bool matrixSearch(Matrix &matrix, int number)
    {
        /*
         * 在每一行从左到右递增和每一列从上到下递增的数组中找出对应的元素
         */
        int rows = matrix.size();
        int columns = matrix[0].size();

        if (rows > 0 && columns > 0)
        {
            int row = 0;
            int column = columns - 1;
            while (row < rows && columns >= 0)
            {
                if (matrix[row][column] == number)
                    return true;
                else if (number < matrix[row][column])
                    column--;
                else
                    row++;
            }
        }

        return false;
    }

    string replaceSpace(string &str)
    {
        // 如果是在原有字符串基础上进行替换的话，从后往前
        if (str.length() == 0)
            return str;

        int spaceNum = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                spaceNum++;
        }
        string newStr((spaceNum * 2 + str.length()), ' ');
        for (int i = 0, j = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                newStr[j] = str[i];
                j++;
            }
            else
            {
                newStr[j] = '%';
                newStr[j+1] = '2';
                newStr[j+2] = '0';
                j += 3;
            }
        }

        return newStr;
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