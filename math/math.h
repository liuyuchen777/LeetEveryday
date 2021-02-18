#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int add(int a, int b)
    {
        return a+b;
    }

    int reverse(int x) 
    {
        int ans = 0, copy = abs(x);

        while (copy > 0) 
        {
            if (INT32_MAX / 10 < ans) 
                return 0;  // check overflow
            ans = ans * 10 + copy % 10;
            copy /= 10;
        }

        return x < 0 ? -ans : ans;
    }

    // very important
    int myAtoi(string s) 
    {
        if (s.size() == 0)
            return 0;

        int i = 0;
        while (s[i] == ' ')
            ++i;

        int flag = 1;
        if (s[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if (isalpha(s[i]))
            return 0;
        
        int result = 0;
        while (i < s.size() && isdigit(s[i]))
        {
            if (flag > 0)
            {
                if (INT32_MAX / 10 < result)
                    return INT32_MAX;
                if (INT32_MAX / 10 == result)
                {
                    if ((s[i] - '0') > 7)
                        return INT32_MAX;
                }
                result = result * 10 + (s[i] - '0');
            }
            else if (flag < 0)
            {
                if (INT32_MIN / 10 > result)
                    return INT32_MIN;
                if (INT32_MIN / 10 == result)
                {
                    if ((s[i] - '0') > 8)
                        return INT32_MIN;
                }
                result = result * 10 - (s[i] - '0');
            }

            ++i;
        }

        return result;
    }

    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;
        if (x == 0 || (x / 10) == 0)
            return true;
        
        long rev = 0;
        int copy = x;
        while (x != 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        if (rev == copy)
            return true;
        return false;
    }

    int romanToInt(string s)
    {
        int res = 0 ;
        map<char, int> map={{'I',1},{'V',5},
					{'X',10},{'L',50},{'C',100},{'D',500},
					{'M',1000}};

		for(int i = 0; i < s.length(); i++)
        {
			if(map[s[i]] < map[s[i+1]])             // 越界字符串值为0
            {
				res += map[s[i+1]] - map[s[i]] ;
				i++;
			} 
            else 
				res += map[s[i]];
        }

        return res;
    }

    string intToRoman(int num) 
    {
        /*
        // elegant but slow and memory use is large
        stringstream ss;
        map<int, string> mymap = {
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
            {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"},
            {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"},
            {900, "CM"}
        };

        for (auto it = mymap.rbegin(); it != mymap.rend(); it++)
        {
            const int key = it->first;
            const string &code = it->second;
            while (num >= key)
            {
                num -= key;
                ss << code;
            }
        }

        return ss.str();
        */

        // ugly but fast 
        string r = "";

        while(num){
            if(num >= 1000){
                num -= 1000;
                r +="M";
            }else if(num >= 900){
                num -= 900;
                r += "CM";
            }else if(num >= 500){
                num -= 500;
                r +="D";
            }else if(num >= 400){
                num -= 400;
                r += "CD";
            }else if(num >= 100){
                num -= 100;
                r +="C";
            }else if(num >= 90){
                num -= 90;
                r += "XC";
            }else if(num >= 50){
                num -= 50;
                r +="L";
            }else if(num >= 40){
                num -= 40;
                r += "XL";
            }else if(num >= 10){
                num -= 10;
                r +="X";
            }else if(num >= 9){
                num -= 9;
                r += "IX";
            }else if(num >= 5){
                num -= 5;
                r +="V";
            }else if(num >= 4){
                num -= 4;
                r += "IV";
            }else if(num >= 1){
                num -= 1;
                r +="I";
            }
        }

        return r;
    }

    int divide(int dividend, int divisor)
    {
        if(dividend == INT32_MIN && divisor == -1) 
            return INT32_MAX;
        if(dividend / divisor > INT32_MAX || dividend / divisor < INT32_MIN)    // why?
            return INT32_MAX;
        
        return dividend / divisor;
    }

    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        vector<string> str;
        int advance = 0;

        for (int i = num2.length() - 1; i >= 0; i--)
        {
            string temp = "";
            advance = 0;
            int loop = num2.length() - 1 - i;

            while (loop--)
                temp += "0";
            for (int j = num1.length() - 1; j >= 0; j--)
            {
                int multi = (num1[j] - '0') * (num2[i] - '0');
                temp += (advance + multi) % 10 + '0';
                advance = (advance + multi) / 10;
            }
            if (advance != 0)
                temp += advance + '0';

            str.push_back(temp);
        }
        //print_str_vec(str);

        string result = "";
        advance = 0;
        int loop = str[str.size() - 1].length();
        for (int i = 0;  i < loop; i++)
        {
            int temp = 0;
            for (int j = 0; j < str.size(); j++)
            {
                if (i < str[j].length())
                {
                    temp += str[j][i] - '0';
                }
            }
            result += (temp + advance) % 10 + '0';
            advance = (temp + advance) / 10;
        }
        if (advance != 0)
            result += advance + '0';
        
        reverseStr(result);

        return result;
    }

    void reverseStr(string& str) 
    { 
        int n = str.length(); 
    
        // Swap character starting from two 
        // corners 
        for (int i = 0; i < n / 2; i++) 
            swap(str[i], str[n - i - 1]); 
    } 

    void print_str_vec(vector<string> vec)
    {
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << endl;
        }
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