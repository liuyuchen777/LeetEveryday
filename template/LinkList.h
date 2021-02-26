// Link List class for normal usage
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

class LinkList
{
private:
    ListNode    *head;
    ListNode    *tail;
    int         len;
public:
    // constructor
    LinkList() : head(nullptr), tail(nullptr), len(0) {}
    LinkList(vector<int> &vec);
    // delete function
    int erase();
    int erase(int pos);
    // insert function
    int insert(int val);
    int insert(ListNode *node);
    int insert(int pos, int val);       // insert after pos
    int insert(int pos, ListNode *node);
    // get function
    ListNode *begin() { return head; }
    ListNode *end() { return tail; }
    int length() { return len; }
    // other func
    void print();
};

LinkList::LinkList(vector<int> &vec)
{
    if (vec.size() == 0)
    {
        len = 0;
        head = nullptr;
        tail = nullptr;
    }

    len = vec.size();
    head = new ListNode(vec[0]);
    ListNode *pointer = head;
    
    for (int index = 1; index < vec.size(); index++)
    {
        pointer->next = new ListNode(vec[index]);
        pointer = pointer->next;
    }

    tail = pointer;
}

int LinkList::insert(int val)
{
    if (len == 0)
    {
        head = new ListNode(val);
        tail = head;
        len++;
    }
    else
    {
        tail->next = new ListNode(val);
        tail = tail->next;
        len++;
    }

    return len;
}

int LinkList::insert(ListNode *node)
{
    if (len == 0)
    {
        head = node;
        tail = node;
        len++;
    }
    else 
    {
        tail->next = node;
        tail = tail->next;
        len++;
    }

    return len;
}

int LinkList::insert(int pos, int val)
{
    // limit judege
    if (pos < 0 || pos > len)
        return -1;

    ListNode *ptr = head;

    while (pos--)
    {  
        ptr = ptr->next;
    }
    ListNode *newNode = new ListNode(val, ptr->next);
    ptr->next = newNode;
    len++;

    return len;
}

int LinkList::insert(int pos, ListNode *node)
{
    // limit judege
    if (pos < 0 || pos > len)
        return -1;
    
    ListNode *ptr = head;

    while (pos--)
    {  
        ptr = ptr->next;
    }
    node->next = ptr->next;
    ptr->next = node;
    len++;

    return len;
}

void LinkList::print()
{
    if (len != 0)
    {
        ListNode *ptr = head;
        do
        {
            cout << ptr->val << " -> ";
            ptr = ptr->next;
        } while (ptr != nullptr);
        cout << endl;
    }
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