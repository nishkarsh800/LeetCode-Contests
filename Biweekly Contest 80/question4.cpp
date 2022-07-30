/*
You are given two strings s and sub. You are also given a 2D character array mappings
where mappings[i] = [oldi, newi] indicates that you may perform the following operation any number of times:
Replace a character oldi of sub with newi.
Each character in sub cannot be replaced more than once.
Return true if it is possible to make sub a substring of s by replacing zero or more characters according to mappings.
Otherwise, return false.
A substring is a contiguous non-empty sequence of characters within a string.

Approach :
1. It can be solved by the sliding window technique.
2. Assume, we have a window between start and end, and the product of all elements < k.
3. Now, let's try to add a new element x. There are two possible cases.
Case-1 ( p >= k)
 This indicates that we must first change the left border of the window so that the result is once more less than k.
Case-2 ( p < k)
 This means we can move the right bound of the window one step further.
 i.e. right - left + 1
*/

class Solution
{
public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        int n = nums.size();
        int left = 0; long long sum = 0, ans = 0;
        for(int right = 0; right < n; right++)
            {
            sum += nums[right];
            while(sum * (right - left + 1) >= k)
            {
                sum -= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

// Time Complexity: O(N),
// Space Complexity : O(1)
