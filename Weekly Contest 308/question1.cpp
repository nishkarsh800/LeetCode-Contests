/*
Problem Statement:

You are given an integer array nums of length n, and an integer array queries of length m.
Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 

Example:

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
    - The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
    - The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
    - The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.

Approach (Binary Search):

1. Sort the given vector 'nums', since the order will not matter.
2. Calculate the prefix sum of 'nums', since we want to know the accumulate sum.
3. Binary Search for each query in 'queries', and the store the index in the result vector 'res'.
4. Return the result vector 'res'.
*/

class Solution 
{
public:   
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    { 
        int n = queries.size();
        // sort the vector, because order will not matter
        sort(nums.begin(), nums.end());
        // find the prefix sum
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        // res[i] will store the answer of each query
        vector<int> res(n);
        // solve for each query
        for(int i = 0; i < n; i++)
        {
            // find the upper bound of sum
            int idx = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            res[i] = idx;
        }
        return res;
    }
};

/*
Time Complexity: O(n*log(n))
Space Complexity: O(1)
*/