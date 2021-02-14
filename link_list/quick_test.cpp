#include <iostream>
#include <vector>
#include "LinkList.h"

using namespace std;

void print_vec(vector<int> &vec)
{
    vector<int>::iterator it = vec.begin();
    for ( ; it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool compareFunction(ListNode *l1, ListNode *l2)
{
    return l1->val < l2->val;
}

bool myFunction(int a, int b)
{
    // 降序
    return a > b;
}

int main()
{
    /*
    ListNode *l1 = new ListNode(1); 
    ListNode *l2 = new ListNode(2); 
    ListNode *l3 = new ListNode(3); 
    ListNode *l4 = new ListNode(4);
    vector<ListNode*> lists = {l1, l3, l4, l2};

    sort(lists.begin(), lists.end(), compareFunction);

    vector<ListNode*>::iterator it = lists.begin();
    for (; it != lists.end(); it++)
    {
        cout << (*it)->val << "  ";
    } 
    cout << endl;
    */

    /*
    vector<int> vec = {1, 3, 4, 2};
    sort(vec.begin(), vec.end(), myFunction);

    print_vec(vec);
    */

    // 插入一个数到有序数组
    int num = 4;
    vector<int> vec= {1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
    int flag = 0;

    for (int index = 0; index < vec.size() - 1; index++)
    {
        if (num <= vec[index])
        {
            vec.insert(vec.begin() + index, num);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        vec.push_back(num);

    print_vec(vec);
}