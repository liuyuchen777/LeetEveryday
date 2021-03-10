#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

template<typename type>
void myReverse(type begin, type end)
{   
    end--;
    while ((end - begin) > 0)
    {
        int temp = *begin;      // how to not use int
        *begin = *end;
        *end = temp;
        begin++;
        end--;
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

    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size(), i;  
        if(n <= 1)            //base case
            return;
			
        for(i = n-2; i >= 0; i--)
        {
            if(nums[i] >= nums[i+1])
                continue;         //check it in descending order..{3,4,1,5,9,8,7,2} it will break at 5 
            else
                break;
        }
        if(i == -1)
        {
            sort(nums.begin(),nums.end());   // sort it in ascending order if array is sorted in descending order
            return;
		}
        int mn=nums[i+1];
        int mini=i+1;

        for(int j=i+1;j<n;j++)
            if(nums[j]>nums[i])
                mn = min(mn,nums[j]), mini = j;   // calculate next greater element i.e. we get 7 as we break the loop at 5 ,...{3,4,1,5,9,8,7,2}
				
        swap(nums[mini], nums[i]);     // swap 5 and 7...{3,4,1,7,9,8,5,2}

        sort(nums.begin() + i + 1, nums.end());    // sort the array after 7 ....{3,4,1,7,2,5,8,9}
    }

    int distributeCandies(vector<int>& candyType) 
    {
        int n = candyType.size() / 2;
        sort(candyType.begin(), candyType.end());
        candyType.erase(unique(candyType.begin(), candyType.end()), candyType.end());
        // unique()函数将重复的元素放到vector的尾部 
        // 然后返回指向第一个重复元素的迭代器再用erase函数擦除从这个元素到最后元素的所有的元素
        
        return min(n, (int)candyType.size());
    }

    vector<int> findErrorNums(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int pre = 0;
        int missing = -1, duplicate = -1;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (pre == *it)
                duplicate = *it;
            else if (pre != (*it - 1))
            {
                missing = *it - 1;
                pre = *it;
            }
            else
                pre = *it;
        }
        if (missing == -1)
            missing = nums.back() + 1;
        

        vector<int> res;
        res.push_back(duplicate);
        res.push_back(missing);

        return res;
    }

    int missingNumber(vector<int>& nums) 
    {
        return nums.size()*(nums.size() + 1)/2 - accumulate(nums.begin(), nums.end(), 0);
    }

    int search(vector<int>& nums, int target) 
    {
        // limit judge
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        // step 1: find the lowest number
        auto it = nums.begin();
        for (; it != nums.end() - 1; it++)
        {
            if (*it > *(it + 1))
                break;
        }
        int lowest_index = it + 1 - nums.begin();
        int r, l;
        // step 2: set binary search area
        if (target >= nums[0])
        {
            l = 0;
            r = lowest_index - 1;
        }
        else if (target < nums[0])
        {
            l = lowest_index;
            r = nums.size() - 1;
        }
        // setp3: binary search
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // step 1: binary search
        int l = 0, r = nums.size() - 1;
        int m, flag = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                flag = 1;
                break;
            }
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        // if not such element in nums
        if (flag == 0)
            return {-1, -1};
        int left = m, right = m;
        // move left and right
        while (left != -1)
        {
            if (nums[left] != target)
                break;
            else
                left--;
        }
        while (right != nums.size())
        {
            if (nums[right] != target)
                break;
            else
                right++;
        }
        right--;
        left++;

        return {left, right};
    }

    int searchInsert(vector<int>& nums, int target) 
    {
        int i;
        
        for (i = 0; i < nums.size(); i++)
        {
            if (target < nums[i])
                break;
        }

        return i;
    }
};