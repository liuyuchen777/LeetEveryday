#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

class Solution {
public:
    int add(int a, int b)
    {
        return a+b;
    }

    bool judgeSort(vector<int> &vec)
    {
        if (vec.size() == 0 || vec.size() == 1)
            return true;

        for (int index = 0; index < vec.size() - 1; index++)
        {
            if (vec[index] > vec[index + 1])
                return false;
        }

        return true;
    }

    vector<int> gen_rand_array(int length)
    {
        vector<int> array;
        default_random_engine random(time(NULL));
        uniform_int_distribution<int> dis(0, 100);

        for (int index = 0; index < length; index++)
        {
            array.push_back(dis(random));
        }

        return array;
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

void bubbleSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j + 1];
                vec[j + 1] = vec[j];
                vec[j] = temp; 
            }
        }
    }
}

void selectionSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min_index])
                min_index = j;
        }
        // exchange
        int temp = vec[min_index];
        vec[min_index] = vec[i];
        vec[i] = temp;
    }
}

void insertSort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int curr = vec[i];
        int pos = i;
        while (vec[pos - 1] > curr && pos > 0)
        {
            vec[pos] = vec[pos - 1];
            pos--;
        }
        vec[pos] = curr;
    }
}

void quickSort(vector<int> &vec)
{
    
}

void _quickSort(vector<int> &vec, int l, int r)
{

}

void partition(vector<int> &vec, int l, int r)
{

}

double cal_time(void (*sort)(vector<int> &))
{
    Solution solve;
    double time = 0;
    clock_t start = clock();
    vector<int> vec = solve.gen_rand_array(10000);

    (*sort)(vec);
    time = (clock() - start) * 1.0 / CLOCKS_PER_SEC;
    if (solve.judgeSort(vec))
        return time;
    else
        return -1.0;
}


