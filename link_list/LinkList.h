#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int add(int a, int b)
    {
        return a+b;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        int sum = 0;
        ListNode *head = nullptr;
        ListNode **pointer = &head;

        while (l1 != nullptr || l2 != nullptr || sum > 0)
        {
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*pointer) = new ListNode(sum % 10);
            sum = sum / 10;
            pointer = &((*pointer) -> next);
        }

        return head;
        */

        // if you don't want to use pointer of pointer, you need to use two pointer: curr and previous
        int sum = l1->val + l2->val;
        ListNode *curr = new ListNode(sum % 10);
        ListNode *head = curr;

        sum /= 10;
        while (l1->next != nullptr || l2->next != nullptr || sum > 0)
        {
            if (l1->next != nullptr)
            {
                l1 = l1->next;
                sum += l1->val;
            }
            if (l2 -> next != nullptr)
            {
                l2 = l2->next;
                sum += l2->val;
            }
            curr->next = new ListNode(sum % 10);
            sum /= 10;
            curr = curr->next;
        }

        return head;
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

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *curr = head, *tmp;
        head = new ListNode(-1, head);  // this is really smart
        tmp = head;
        while (--n)
            curr = curr->next;
        while (curr!= nullptr && curr->next!=nullptr)
        {
            tmp = tmp->next;
            curr = curr->next;
        }
        tmp->next = tmp->next->next;

        return head->next;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *head = res;

        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        else if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;

        do
        {
            if (l1->val <= l2->val)
            {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        } while (l1 != nullptr && l2 != nullptr);

        if (l1 == nullptr)
            res->next = l2;
        else
            res->next = l1;

        return head->next;
    }

    ListNode *init_linklist_order(int max)
    {
        ListNode *head = new ListNode(0);
        ListNode *pointer = head;

        for (int index = 1; index < max; index++)
        {
            pointer->next = new ListNode(index);
            pointer = pointer->next;
        }

        return head;
    }

    ListNode *init_linklist_vec(vector<int> &vec)
    {
        /*
        vector<int>::iterator it = vec.begin();
        ListNode *head = nullptr;
        ListNode **pointer = &head;

        for (; it != vec.end(); it++)
        {
            *(pointer) = new ListNode(*it);
            pointer = &((*pointer)->next);
        }

        return head;
        */
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

    static bool compareFunction(ListNode *l1, ListNode *l2)
    {
        return l1->val < l2->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {   
        vector<ListNode*>::iterator it = lists.begin();
        ListNode *ptr = new ListNode(-1, nullptr);
        ListNode *head = ptr;

        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());  // remove all nullptr
        sort(lists.begin(), lists.end(), compareFunction);

        while (lists.size() != 0)
        {          
            ListNode *curr = lists[0];
            ptr->next = curr;
            ptr = ptr->next;
            lists.erase(lists.begin());
            if (curr->next != nullptr)
            {
                // lists.push_back(curr->next);
                // 把一个数插入有序数列
                int flag = 0;
                for (int index = 0; index < lists.size(); index++)
                {
                    if (curr->next->val < lists[index]->val)
                    {
                        lists.insert(lists.begin() + index, curr->next);
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    lists.push_back(curr->next);
                }
            }
        }

        return head->next;
    }

    void print_LL_vec(vector<ListNode*> &vec) 
    {
        vector<ListNode*>::iterator it = vec.begin();
        for (; it != vec.end(); it++)
        {
            cout << (*it)->val << "  ";
        }
        cout << endl;
    }

    ListNode* swapPairs(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *pre = new ListNode(-1, head);
        ListNode *curr = pre->next;
        head = pre;

        while (curr != nullptr && curr->next != nullptr)
        {
            // change node
            pre->next = curr->next;
            curr->next = pre->next->next;
            pre->next->next = curr;
            // move pointer
            pre = pre->next->next;
            curr = curr->next;
        }

        return head->next;
    }

    ListNode* rotateRight(ListNode* head, int k) 
    {
        // limit judge
        if (head == nullptr || head->next == nullptr)
            return head;
        // first step, know the length of the linklist
        int length = 1;
        ListNode *result = new ListNode(-1, head);
        ListNode *curr = head;
        ListNode *curr2 = head;

        do
        {
            length++;
            curr = curr->next;
        } while (curr->next != nullptr);
        k = k % length;
        for (int index = 0; index < (length - k - 1); index++)
        {
            curr2 = curr2->next;
        }
        curr->next = result->next;
        result->next = curr2->next;
        curr2->next = nullptr;
        
        return result->next;
    }

    ListNode* deleteDuplicates(ListNode* head) 
    {
        // limit judge
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *curr = head;

        do
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        } while(curr->next != nullptr);

        return head;
    }

    ListNode* deleteDuplicates2(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *result = new ListNode(-1, head);
        ListNode *pre = result;
        ListNode *curr = result->next;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                while (curr->next != nullptr && curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                pre->next = curr->next;
                curr = curr->next;            
            }
            else
            {
                pre = curr;
                curr = curr->next;
            }
        } 

        return result->next;
    }

    void reversePrint(ListNode *head)
    {
        stack<ListNode *>nodes;
        ListNode *phead = head;

        while (phead != nullptr)
        {
            nodes.push(phead);
            phead = phead->next;
        }
        while (!nodes.empty())
        {
            phead = nodes.top();
            cout << phead->val << "  ";
            nodes.pop();
        }
        cout << endl;
    }

    void reversePrintRecursive(ListNode *head)
    {
        if (head != nullptr)
        {
            if (head->next != nullptr)
                reversePrintRecursive(head->next);
            cout << head->val << "  ";
        }
    }
};

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

/*
int main()
{
    Solution solve;
    ListNode *head = solve.init_linklist_order(20);
    vector<int> vec = {1};
    ListNode *head2 = solve.init_linklist_vec(vec);

    solve.print_LinkList(head);
    solve.print_LinkList(head2);
}
*/