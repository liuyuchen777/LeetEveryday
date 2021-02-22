#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

int g_len = 10000;

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
    if (vec.size() > 0)
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

void __quickSort(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = vec[i];
        while (i < j)
        {
            while (i < j && vec[j] >= x)    // 从右到左寻找比x大的
                j--;
            if (i < j)
                vec[i++] = vec[j];          // 第一次放到x的位置，第二次放到之前j的位置
            while (i < j && vec[i] < x)     // 从左到右寻找比x小的
                i++;
            if (i < j)
                vec[j--] = vec[i];
        }
        vec[i] = x;

        __quickSort(vec, l, i - 1);
        __quickSort(vec, i + 1, r);
    }
}

void quickSort(vector<int> &vec)
{
    __quickSort(vec, 0, vec.size() - 1);
}

void swap(vector<int> &vec, int a, int b)
{
    // swap without using temp var
    vec[a] = vec[a] + vec[b];
    vec[b] = vec[a] - vec[b];
    vec[a] = vec[a] - vec[b];
}

void shellSort(vector<int> &vec)
{
    if (vec.size() > 1)
    {
        for (int gap = vec.size() / 2; gap > 0; gap /= 2)
        {
            // increment gap, from vec 1/2 max size to 0
            for (int i = gap; i < vec.size(); i++)
            {
                // 从第gap个元素，逐个对其所在组进直接插入排序
                int j = i;
                while (j - gap >= 0 && vec[j] < vec[j - gap])
                {
                    // 通过交换的方式进行希尔排序
                    swap(vec, j, j - gap);
                    j -= gap;
                }
                /*
                // 通过移动的方式
                int j = i; 
                int temp = vec[j];
                if (vec[j] < vec[j - gap])
                {
                    while (j - gap >= 0 && temp < vec[j - gap])
                    {
                        vec[j] = vec[j - gap];
                        j -= gap;
                    }
                    vec[j] = temp;
                }
                */
            }
        }
    }
}

void merge(vector<int> &vec, int l, int m, int r)
{
    int i = 0, j = 0, k = l;
    vector<int> L(vec.begin() + l, vec.begin() + m + 1);
    vector<int> R(vec.begin() + m + 1, vec.begin() + r + 1);
    // 后面是一个合并两个有序数组的过程
    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < L.size())
    {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < R.size())
    {
        vec[k] = R[j];
        j++;
        k++;
    }

}

void __mergeSort(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        __mergeSort(vec, l, m);
        __mergeSort(vec, m + 1, r);

        merge(vec, l, m, r);
    }
}

void mergeSort(vector<int> &vec)
{
    __mergeSort(vec, 0, vec.size() - 1);
}

/*
void heapify(vector<int> &vec, int n, int i)
{

}

void heapSort(vector<int> &vec)
{
    // create heap
    for (int i = vec.size() / 2; i >= 0; i--)
        heapify(vec, vec.size(), i);
    
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        swap(vec, 0, i);
        heapify(vec, i, 0);
    }
}
*/

double cal_time(void (*sort)(vector<int> &))
{
    Solution solve;
    double time = 0;
    clock_t start = clock();
    vector<int> vec = solve.gen_rand_array(g_len);

    (*sort)(vec);
    time = (clock() - start) * 1.0 / CLOCKS_PER_SEC;
    if (solve.judgeSort(vec))
        return time;
    else
        return -1.0;
}


