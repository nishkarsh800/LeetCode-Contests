/*
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.

 

Example 1:

Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
Example 2:

Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is: 
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be: 
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.

Approach:
First find the difference between two arrays. Then use binary search to find the maximum possible difference value so that we could reduce all larger differences and make k ≥ 0. Then we simulate the reduction of the maximum difference and k, and use priority queue to remove all extra k from the array for optimal answer.
*/

class Solution 
{
public:
    bool val(vector<int> &v, int mark, long long k) 
    {
        long long cnt = 0;
        for (auto a : v) 
        {
            if (a > mark) 
            {
                cnt += a - mark;
            }
        }
        return cnt <= k;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        vector<int> diff(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) 
        {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        long long left = 0, right = *max_element(diff.begin(), diff.end()), ans = 0, k = k1 + k2;
        while (left <= right) 
        {
            long long mid = left + (right - left) / 2;
            if (val(diff, mid, k)) 
            {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        long long sum = 0;
        for (int i = 0; i < nums1.size(); ++i) 
        {
            if (diff[i] > ans && k > 0) 
            {
                int dif = diff[i] - ans;
                k -= dif;
                diff[i] -= dif;
            }
        }
        priority_queue<int> pq;
        for (auto a : diff) pq.push(a);
        while (k > 0 && pq.top() > 0) 
        {
            int tmp = pq.top();
            pq.pop();
            --tmp;
            --k;
            pq.push(tmp);
        }
        if (pq.top() == 0) return 0;
        while (!pq.empty() && pq.top() > 0) 
        {
            sum += 1LL * pq.top() * pq.top();
            pq.pop();
        }
        return sum;       
    }
};

// Time Complexity:  O(nlogn + nlogr), r is max((abs(i-j) for i, j in itertools.izip(nums1, nums2))
// Space Complexity: O(n)
