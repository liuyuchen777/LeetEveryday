#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class ListNode 
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        // 空数组
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        // push_back进去，排序，然后和上一题一样
        vector<Interval> result;

        intervals.push_back(newInterval);
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

    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        // faster approach
        if(intervals.size()==0)
            return {newInterval};
        
        vector<vector<int>> result;     // 保存结果
        int minp = newInterval[0]; 
        int maxp = newInterval[1];
        int i=0;

        if(intervals[0][0]> maxp)
        { //codition if newInterval must be aur fast interval 
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(intervals[intervals.size()-1][1]<minp)
        { // condition if newinterval must be our last interval
            intervals.push_back(newInterval);
            return intervals;
        }

        // for mid insert of interval
        while (i < intervals.size())
        {   // 找到插入位置
            if(minp< intervals[i][0])
                break;
            if(intervals[i][0]<=minp && intervals[i][1]>=minp)
                break;
            result.push_back(intervals[i]);
            i++;
        }

        minp = min(minp , intervals[i][0]);

        while (i < intervals.size())
        {
            if(intervals[i][0] > maxp)
            {
                i--;
                break;
            }
            if(intervals[i][0]<=maxp && intervals[i][1]>=maxp)
            {
                maxp = max(maxp , intervals[i][1]);
                break;
            }
            i++;
        }

        result.push_back({minp , maxp});
        
        i++;
        while (i < intervals.size())
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }

    void sortColors(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
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

    ListNode* insertionSortList(ListNode* head) 
    {
        /*
        // slow but passed
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *head2 = new ListNode(head->val, nullptr);
        ListNode *result = new ListNode(-1024, head2);
        ListNode *curr = head->next;

        while (curr != nullptr)
        {
            ListNode *ptr1 = result;
            ListNode *ptr2 = result->next;
            while (ptr2 != nullptr && ptr2->val <= curr->val)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            // insert node
            ptr1->next = new ListNode(curr->val, ptr1->next);
            // move curr
            curr = curr->next;
        }
        

        return result->next;
        */
        if(head == nullptr || head->next == nullptr) 
            return head;
        
        ListNode* result = new ListNode(-1024, head);    
        ListNode * curr = head;
        ListNode* prev = curr;
        curr = curr->next ;

        while(curr != nullptr)
        {
            if(prev->val < curr->val)
            {   // 顺序判断
                prev = curr ;
                curr = curr->next ;
            }
            else
            {   
                ListNode* next = curr->next; 
                ListNode* itr = result->next;   // 从头开始
                ListNode* itr_prev = result;    // 头的前一个
                
                while (itr->val < curr->val)    // 向前插入
                {
                    itr_prev = itr ;
                    itr = itr->next ;
                }

                itr_prev->next = curr;
                curr->next = itr; 
                prev->next = next; 
                curr = next ;
            }
        }

        return result->next; 
    }

    ListNode* sortList(ListNode* head) 
    {
        // O(nlogn) time and O(1) space -> merge sort
        
    }

    void print_interval(vector<vector<int>> &vec)
    {
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            cout << "(" << (*it)[0] << ", " << (*it)[1] << ")" << "  ";
        }
        cout << endl;
    }

    ListNode *init_linklist_vec(vector<int> &vec)
    {
        if (vec.size() == 0)
            return nullptr;
        
        ListNode *head = new ListNode(vec[0]);
        ListNode *pointer = head;
        
        for (int index = 1; index < vec.size(); index++)
        {
            pointer->next = new ListNode(vec[index]);
            pointer = pointer->next;
        }

        return head;
    }

    void print_LinkList(ListNode *ptr)
    {
        if (ptr != nullptr)
        {
            do
            {
                cout << ptr->val << " -> ";
                ptr = ptr->next;
            } while (ptr != nullptr);
        cout << endl;
        }
    }

    static bool compareFunction(ListNode *l1, ListNode *l2)
    {
        return l1->val < l2->val;
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

bool judge_same_linklist(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr && l2 == nullptr)
        return true;
    else if ((l1 == nullptr && l2 != nullptr) || (l1 != nullptr && l2 == nullptr))
        return false;
    
    do
    {
        if (l1->val != l2->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    } while (l1 != nullptr && l2 != nullptr);

    if (l1 == nullptr && l2 == nullptr)
        return true;
    else
        return false;
}