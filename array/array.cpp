#include <gtest/gtest.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            for (int j = i + 1; j < (int)nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }

    int maxArea(vector<int>& height) 
    {
        /*
        // the dumpest approach
        int max_val = 0;
        for (int i = 0; i < (int)height.size(); i++)
        {
            for (int j = i + 1; j < (int)height.size(); j++)
            {  
                int temp_val = (j - i) * ((height[i] < height[j])? height[i]: height[j]);
                if (temp_val > max_val)
                {
                    max_val = temp_val;
                }
            }
        }

        return max_val;
        */
       
       // two-point appraoch
       size_t i = 0, j = height.size() - 1;
       int max_val = 0;

       while (i != j)
       {
            int temp_val = (j - i) * ((height[i] < height[j])? height[i]: height[j]);
            if (temp_val > max_val)
            {
               max_val = temp_val;
            }
            if (height[i] < height[j])
                i++;
            else
                j--;
       }

       return max_val;
    }

    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;

        if (nums.size() < 3)
        {
            return result;
        }
        else
        {
            /*
            // the dumpest way
            sort(nums.begin(), nums.end());
            for (int i = 0; i < (int)nums.size(); i++)
            {
                for (int j = i + 1; j < (int)nums.size(); j++)
                {
                    for (int k = j + 1; k < (int)nums.size(); k++)
                    {  
                        if ((nums[i] + nums[j] + nums[k]) == 0)
                        {
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            // need to judge if there already sequence in the result
                            result.push_back(temp);
                        }
                    }
                }
            }
            return result;
            */
            
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            int length = nums.size() - 1, left, right;
            for (int index = 0; index <= length; index++)
            {
                if (index > 0 && nums[index - 1] == nums[index]) 
                    continue; 
                
                left = index + 1;
                right = length;
                while ( left < right )
                {
                    if ( nums[index] + nums[left] + nums[right] < 0 ) ++left;
                    else if ( nums[index] + nums[left] + nums[right] > 0 ) --right;
                    else
                    {
                        vector<int> anotherAnswer { nums[index], nums[left], nums[right] };
                        ans.push_back(anotherAnswer);
                        ++left;
                        // 防止把相同的答案放进去
                        while ( left < right && nums[left] == nums[left - 1] ) ++left;
                    }   
                }    
            }     
            return ans;
        }
    }

    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int length = nums.size() - 1;
        int diff = INT32_MAX;   // 当前最小值
        int prev = diff;        // 之前的最小值
        int res = diff;         // 结果

        for (int index = 0; index < length - 1; index++)
        {
            int left = index + 1;
            int right = length;

            while(left < right)
            {
                int sum = nums[index] + nums[right] + nums[left];
                diff = min(diff, abs(sum - target));
                if (prev != diff)
                    res = sum;
                prev = diff;
                if (sum <= target)
                    left++;
                else
                    right--;
            }
        }

        return res;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;

        if ((start == nums.size()) || (nums[start] * k > target) || (target > nums.back() * k))
        {
            return res;
        }

        if (k == 2)
            return twoSum(nums, target, start);

        for (int index = start; index < (nums.size()-1); index++)
        {
            if (index == start || nums[index - 1] != nums[index])
            {
                for (auto &set : kSum(nums, target - nums[index], index+1, k-1))
                {
                    res.push_back({nums[index]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        int left = start, right = nums.size() - 1;

        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if ((sum < target) || (left > start && nums[left] == nums[left-1]))
            {
                left++;
            }
            else if ((sum > target) || (right < nums.size()-1 && nums[right] == nums[right+1]))
            {
                right--;
            }
            else
            {
                res.push_back({nums[left], nums[right]});
                left++;
            }
        }

        return res;
    }

    int removeDuplicates(vector<int> &nums)
    {
        /*
        if (nums.size() < 2)
        {
            return nums.size();
        }

        sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin() + 1;
        int prev = nums[0];


        while(it != nums.end())
        {
            if (*it == prev)
                it = nums.erase(it);
            else
            {
                prev = *it;
                it++;
            }
        }

        return nums.size();
        */

       // solution 2
       
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

TEST(remove, common1)
{
    Solution solve;
    vector<int> array = {1, 1, 2};
    vector<int> ans = {1, 2};

    EXPECT_EQ(solve.removeDuplicates(array), 2);
    EXPECT_EQ(judge_same_vector(array, ans), true);
}

TEST(remove, common2)
{
    Solution solve;
    vector<int> array = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> ans = {0, 1, 2, 3, 4};

    EXPECT_EQ(solve.removeDuplicates(array), 5);
    EXPECT_EQ(judge_same_vector(array, ans), true);
}

TEST(threeSumClose, common1)
{
    Solution solve;
    vector<int> array = {-1, 2, 1, -4};
    int target = 1;
    int ans = 2;

    EXPECT_EQ(solve.threeSumClosest(array, target), ans);
}

TEST(JudgeMUlti, common1)
{
    vector<vector<int>> array1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> array2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    EXPECT_EQ(judge_same_multi_vector(array1, array2), true);
}

TEST(SumupTest, basicfun1)
{
    Solution solve;

    vector<int> arr = {3, 3};
    int target = 6;
    vector<int> res = solve.twoSum(arr, target);

    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 1);
}

TEST(SumupTest, basicfun2)
{
    Solution solve;

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = solve.twoSum(arr, target);

    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 1);
}

TEST(SumupTest, empty1)
{
    Solution solve;

    vector<int> arr = {};
    int target = 9;
    vector<int> res = solve.twoSum(arr, target);

    EXPECT_EQ(res.size(), 0);
}

TEST(maxArea, common1)
{
    Solution solve;
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    EXPECT_EQ(solve.maxArea(arr), 49);
}

TEST(maxArea, common2)
{
    Solution solve;
    vector<int> arr = {1, 1};

    EXPECT_EQ(solve.maxArea(arr), 1);
}

TEST(maxArea, common3)
{
    Solution solve;
    vector<int> arr = {4, 3, 2, 1, 4};

    EXPECT_EQ(solve.maxArea(arr), 16);
}

TEST(maxArea, common4)
{
    Solution solve;
    vector<int> arr = {1, 2, 1};

    EXPECT_EQ(solve.maxArea(arr), 2);
}

TEST(maxArea, common5)
{
    Solution solve;
    vector<int> arr = {2, 3, 4, 5, 18, 17, 6};

    EXPECT_EQ(solve.maxArea(arr), 17);
}


TEST(threeSum, value1)
{
    Solution solve;
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = solve.threeSum(arr);
    vector<vector<int>> res = {{-1, -1, 2}, {-1, 0, 1}};

    vector<int> arr2 = {};
    vector<vector<int>> result2 = solve.threeSum(arr2);
    vector<vector<int>> res2 = {};
    
    EXPECT_EQ(judge_same_multi_vector(result, res), true);
    EXPECT_EQ(judge_same_multi_vector(result2, res2), true);
}


TEST(JudgeFun, simple1)
{
    vector<int> vec1 = {-1, -1, 0};
    vector<int> vec2 = {0, -1, -1};

    EXPECT_EQ(judge_same_vector(vec1, vec2), true);
}

TEST(JudgeMulti, simple1)
{
    
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}