#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

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

    void __preorderTraversal(TreeNode* root, vector<int> &res) 
    {
        if (root == nullptr)
            return;
        
        res.push_back(root->val);
        __preorderTraversal(root->left, res);
        __preorderTraversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        __preorderTraversal(root, res);
        return res;
    }

    void __postorderTraversal(TreeNode* root, vector<int> &res) 
    {
        if (root == nullptr)
            return;
        
        __postorderTraversal(root->left, res);
        __postorderTraversal(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        __postorderTraversal(root, res);
        return res;
    }

    vector<int> postorderTraversal2(TreeNode* root)
    {
        stack<TreeNode *> myStack;
        vector<int> res;



        return res;
    }

    TreeNode* createTree(vector<int> &list, int start){
        if (list[start] == -1) {
            return NULL;
        }

        TreeNode* root = new TreeNode(list[start]);

        int lnode = 2 * start + 1;
        int rnode = 2 * start + 2;
        if ( lnode > list.size() -1) {
            root -> left = NULL;
        }else{
            root -> left = createTree(list, lnode);
        }

        if (rnode > list.size() -1) {
            root -> right =NULL;
        }else{
            root -> right = createTree(list, rnode);
        }

        return root;
    }

    void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            std::cout << node->val << std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }
    // get tree depth
    int getMaxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
    }

    void __addOneRow(TreeNode *node, const int v, int d)
    {
        if (node == nullptr)
            return;
        else if (d == 1)
        {
            node->left = new TreeNode(v, node->left, nullptr);
            node->right = new TreeNode(v, nullptr, node->right);
            return;
        }
        else
        {
            __addOneRow(node->left, v, d - 1);
            __addOneRow(node->right, v, d - 1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        if (d == 1)
        {
            root = new TreeNode(v, root, nullptr);
            return root;
        }

        __addOneRow(root, v, d - 1);

        return root;
    }
};