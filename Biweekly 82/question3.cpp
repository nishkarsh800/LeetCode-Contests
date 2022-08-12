/**
 Minimum sum of Squared Difference.

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
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[i] <= 105
0 <= k1, k2 <= 109





TC : O(NlogN)
Space Complexity: O(1)



**/



// Here is the Solution:

class Solution 
{
public:
    //why using set over priority_queue ?
    
    //General idea:
    //We are pre-calculating the count of each difference
    //Taking out max number from set by *set.rbegin()
    //if the count of the number is less than k, we decrease k by that amount
    //otherwise we break making the k to be zero
    //This way it will not give TLE as it will decrease k for sure as n <= 10^5 and k<= 10^9
    
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        set<long long> st;
        int n= nums1.size();
        int k=  k1 + k2;
        
        //map to store count of differnce at each index
        unordered_map<long long, int> mp;
        
        //traversing to get count
        for(int i= 0; i< n; ++i){
            long long x= (long long)abs(nums1[i] - nums2[i]);
            
            //storing unique values into set
            st.insert(x);
            //taking count
            mp[x]++;
        }
        
        long long sum= 0;
        while(k)
        {
            //if set is empty, return
            if(st.empty())
                break;
            //taking out max element form set
            long long x= *st.rbegin();
            
            //if the max element si itself 0, then all other value would be definitely 0, so return 0
            //there is no negative values, we keep absolute difference
            if(x == 0)
                return 0;
            
            int cnt= mp[x];
            //if count is less than or equal to current k, count of current number would become 0 
            //and count of (current number - 1) would increase by cnt;
            if(cnt <= k)
            {
                mp[x] = 0;
                mp[x-1]+= cnt;
                k-= cnt;
            }
            
            //if count is more than k, the count is current would decrease by k 
            //and count of (current number - 1) would increase by k
            //we break as k = 0 now.
            else
            {
                mp[x]= cnt- k;
                mp[x-1]+= k;
                break;
            }
            
            //insert (current number - 1) as it is possible that this number is not in set.
            st.insert(x-1);
            
            //erase the element as it's work is done
            st.erase(x);
        }
        
        //take the count of count of each number
        //multiply the sqaure of number with its count
        for(auto& x: mp)
        {
            sum+= (x.first * x.first * x.second);
        }
        return sum;
        
        //so why to use set ?
        //because we can erase element from set easily.
    }
};