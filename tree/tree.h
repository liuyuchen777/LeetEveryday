#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using Matrix = std::vector<vector<int>>;

class TreeNode 
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
bool operator==(vector<int> &vec1, vector<int> &vec2)
{
    if (vec1.size() != vec2.size())
        return false;

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    if (vec1 == vec2)
        return true;
    else
        return false;
}


bool operator==(Matrix &mat1, Matrix &mat2)
{
    if (mat1.size() != mat2.size())
        return false;
    if (mat1[0].size() != mat2[0].size())
        return false;

    for (auto it11  = mat1.begin(), it12 = mat2.begin(); it11 != mat1.end(); it11++, it12++)
    {
        for (auto it21 = (*it11).begin(), it22 = (*it12).begin(); it21 != (*it11).end(); it21++, it22++)
        {
            if (*it21 != *it22)
                return false;
        }
    }

    return true;
}
*/

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

bool judge_same_vector(vector<int> &vec1, vector<int> &vec2)        // vector中元素是否相同
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

class Solution 
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    void __inorderTraversal(TreeNode* root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        
        __inorderTraversal(root->left, res);
        res.push_back(root->val);
        __inorderTraversal(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        // recursive
        vector<int> res;
        __inorderTraversal(root, res);
        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) 
    {
        // iterative
        vector<TreeNode *> myStack;
        vector<int> res;
        TreeNode *curr = root;

        while (curr != nullptr || !myStack.empty())
        {
            while (curr != nullptr)
            {
                myStack.push_back(curr);
                curr = curr->left;
            }
            curr = myStack[myStack.size() - 1];
            myStack.pop_back();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }

    vector<int> __preorderTraversal(TreeNode* root, vector<int> &res) 
    {
        
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        __preorderTraversal(root, res);
        return res;
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