/*
Problem Statement:

You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:
1. The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
2. The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
3. The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elementsis 1. 
   For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.

Return true if the array has at least one valid partition. Otherwise, return false.

Approach: (Dynamic Programming)

1. For the current element, dp[i] indicates if the array can be partitioned up to that element.
2. For element dp[i + 1], the partition is valid if:
    i. dp[i - 1] == true and we have a partition of two elements, or,
    ii. dp[i - 2] == true and we have a partition of three elements.
3. Since we only need to look 3 elements back, we can use a rolling dp array for constant memory complexity.

*/
class Solution {

public:
    bool validPartition(vector<int>& nums) 
    {
        bool dp[4]={true, false, n[0] == n[1], false};
        for (int i=2; i<n.size(); ++i) 
        {
            bool two=n[i]== n[i-1];
            bool three=(two && n[i] == n[i-2]) || (n[i]-1 == n[i-1] && n[i]-2 == n[i-2]);
            dp[(i+1)%4]=(dp[(i-1)%4] && two) || (dp[(i-2)%4] && three);
        }
        return dp[n.size()%4];
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/