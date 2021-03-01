#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

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

class Solution {
public:
    int add(int a, int b)
    {
        // test function
        return a + b;
    }

    // func
    vector<string> split(const string &str, const string &pattern)
    {   // 字符串分割
        vector<string> res;
        if(str == "")
            return res;

        string strs = str;
        if (strs[strs.length() - 1] != '/')
            strs += '/';

        if (strs[0] == '/')
            strs = strs.substr(1, strs.length() - 1);

        size_t pos = strs.find(pattern);

        while(pos != strs.npos)
        {
            string temp = strs.substr(0, pos);
            res.push_back(temp);
            //去掉已分割的字符串,在剩下的字符串中进行分割
            strs = strs.substr(pos + 1, strs.size());
            pos = strs.find(pattern);
        }
        /*
        for (auto it = res.begin(); it != res.end(); it++)
        {
            if (*it == "")
                res.erase(it);
        }
        */

        return res;
    }



    string simplifyPath(string path) 
    {
        vector<string> vec = split(path, "/");
        vector<string> myStack;
        string res = "";

        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            if (*it == "." || *it == "")
                continue;
            else if (*it == "..")
            {
                if (myStack.size() != 0)
                    myStack.pop_back();
            }
            else
                myStack.push_back(*it);
        }
        
        for (auto it = myStack.begin(); it != myStack.end(); it++)
        {
            res += "/" + *it;
        }

        return res.size() == 0 ? "/" : res;
    }

    string simplifyPath2(string path) 
    {
        vector<string> parts {};
        int i = 0;

        while (i < path.size()) 
        {
            if (path[i] != '/') 
            {
                string cur = "";
                while (i < path.size() && path[i] != '/')
                    cur += path[i++];
                if (cur == "..") 
                {
                    if (!parts.empty())
                        parts.pop_back();
                }
                else if (cur != ".")
                    parts.push_back(cur);
            }
            else
                i++;
        }

        string result = "";
        for (string s : parts)
            result += "/" + s;
        
        return result.empty() ? "/" : result;
    }

    string simplifyPath3(string path)
    {
        if (path == "/")
            return "/";

        vector<string> res;

        string strs = path.substr(1, path.size());
        if (strs[strs.length() - 1] != '/')
            strs += "/";

        size_t pos = strs.find("/");

        while (pos != strs.npos)
        {
            string temp = strs.substr(0, pos);
            if (temp == "..") 
                {
                    if (!res.empty())
                        res.pop_back();
                }
                else if (temp != "." && temp != "")
                    res.push_back(temp);
            strs = strs.substr(pos + 1, strs.size());
            pos = strs.find('/');
        }

        string result = "";
        for (string s : res)
            result += "/" + s;
        
        return result.empty() ? "/" : result;
    }
};