/**
Subarray With Elements Greater Than Varying Threshold

You are given an integer array nums and an integer threshold.

Find any subarray of nums of length k such that every element in the subarray is greater than threshold / k.

Return the size of any such subarray. If there is no such subarray, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,4,3,1], threshold = 6
Output: 3
Explanation: The subarray [3,4,3] has a size of 3, and every element is greater than 6 / 3 = 2.
Note that this is the only valid subarray.
Example 2:

Input: nums = [6,5,6,5,8], threshold = 7
Output: 1
Explanation: The subarray [8] has a size of 1, and 8 > 7 / 1 = 7. So 1 is returned.
Note that the subarray [6,5] has a size of 2, and every element is greater than 7 / 2 = 3.5. 
Similarly, the subarrays [6,5,6], [6,5,6,5], [6,5,6,5,8] also satisfy the given conditions.
Therefore, 2, 3, 4, or 5 may also be returned.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], threshold <= 109
**/

// Here is the Solution:

class Solution 
{
public:
    int validSubarraySize(vector<int>& nums, int threshold)
     {
        
        int n = nums.size();
        
        // find the index of next smaller for every element on left
        
        vector<int> left_smaller(n, -1);
       
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            // remove the index of greater element from stack
            
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            
            // if no smaller element on left
            
            if(st.empty())  
            {
                left_smaller[i] = -1;
            }
            
            // if smaller element is present on left
            
            else
            {
                left_smaller[i] = st.top();
            }
            
            // push the index of curr element
            
            st.push(i);
        }
        
        // empty the stack for finding the next smaller on right
        
        while(!st.empty())
        {
            st.pop();
        }
        
        // find the index of next smaller on right
        
        vector<int> right_smaller(n, n);
        
        for(int i = n - 1; i >= 0; i--)
        {
            // remove the index of greater element from stack
            
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            
            // if no smaller element on right
            
            if(st.empty())
            {
                right_smaller[i] = n;
            }
            
            // if smaller element is present on right
            
            else
            {
                right_smaller[i] = st.top();
            }
            
            // push the index of curr element
            
            st.push(i);
        }
        
        // now find the size of subarray, which will contains all the elements greater than (threshold / size of subarray)
        
        for(int i = 0; i < n; i++)
        {
            // find size of subarray, considering nums[i] as minimum of subarray
            
            int k = right_smaller[i] - left_smaller[i] - 1;
            
            // find the minimum value required for subarray, by doing (threshold / k)
            
            double min_value_required = (double) threshold / k;
            
            // check that if minimum of subarray(nums[i]) is greater than min_value_required, then size of subarray is found, return size(k)
            
            // if minimum of subarray(nums[i]) is greater than min_value_required, then every element of subarray will be greater than min_value_required
            
            if(nums[i] > min_value_required)
            {
                return k;
            }
        }
        
        return -1;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)