#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_vec_int(vector<int> &vec)
{
    vector<int>::iterator it = vec.begin();
    for ( ; it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int len = nums1.size() + nums2.size();
        vector<int> mergeArray(len);
        int i = 0, j = 0, index = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                mergeArray[index] = nums1[i];
                i++;
            }
            else
            {
                mergeArray[index] = nums2[j];
                j++;
            }
            index++;
        }
        while (i < nums1.size())
        {
            mergeArray[index] = nums1[i];
            i++;
            index++;
        }
        while (j < nums2.size())
        {
            mergeArray[index] = nums2[j];
            j++;
            index++;
        }

        if (len % 2 == 0)
            return (mergeArray[len / 2 - 1] + mergeArray[len / 2]) / 2.0;
        else
            return mergeArray[len / 2];
    }
};