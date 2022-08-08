/**
2317. Maximum XOR After Operations

You are given a 0-indexed integer array nums. In one operation, select any non-negative integer x and an index i, then update nums[i] to be equal to nums[i] AND (nums[i] XOR x).

Note that AND is the bitwise AND operation and XOR is the bitwise XOR operation.

Return the maximum possible bitwise XOR of all elements of nums after applying the operation any number of times.

 

Example 1:

Input: nums = [3,2,4,6]
Output: 7
Explanation: Apply the operation with x = 4 and i = 3, num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2.
Now, nums = [3, 2, 4, 2] and the bitwise XOR of all the elements = 3 XOR 2 XOR 4 XOR 2 = 7.
It can be shown that 7 is the maximum possible bitwise XOR.
Note that other operations may be used to achieve a bitwise XOR of 7.
Example 2:

Input: nums = [1,2,3,9,2]
Output: 11
Explanation: Apply the operation zero times.
The bitwise XOR of all the elements = 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11.
It can be shown that 11 is the maximum possible bitwise XOR.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 108
**/

/**
Approach:
* nums[i] AND (nums[i] XOR x)
* with the above operation we can modify any nums[i] right
* as we are taking AND, we can say that none of the bits of nums[i] can be converted from 0 to 1
on the other hand, we can convert a bit from 1 to 0
as we can choose x such that nums[i]^x = 0 at that ith bit then its & with nums[i] will result in 0
1&0 = 0
* now to maximize the final answer we want as many 1 as possible in the final value
* So, if there exist atleast a single bit at ith position whose value is 1, we can have a combination of other bits to give XOR =1 for that bit
how?
        * we can make all the other elements ith bit = 0 then the xor of all the elements at this ith bit will be
        * 1^0^0...^0 = 1
* So, in conclusion if the ith bit of any element is 1 then the ith bit of our final answer will be 1 too and if all the elements has their ith bit =0 then the ith bit of our answer will be 0
* you can clearly guess from the above statement that we just want the OR of all the elements
**/

// Time Complexity: O(N)
// Space Complexity: O(N) it mainly depends on the size of input and size of vector.
class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans |= nums[i];
        return ans;
    }
};