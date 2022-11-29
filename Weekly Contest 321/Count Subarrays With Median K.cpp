/*   Input: nums = [3,2,1,4,5], k = 4
Output: 3


- sort the array [1,2,3,4,5] here median=3 {Array is odd} 
   g==s; g=4,5 and s=1,2
- if array is even, [1,2,3,4] median will be 2 
   g-1=s; g=3,4 and s=1

- if we want element i to be a part of subarray then starting idx should be 
b/w 0 to i and ending idx should be b/w i to n-1.

Ex: nums = [3,2,1,4,5]
            0 1 2 3 4 for 4, starting idx must be b/w 0 to 3 and ending idx will be from 3 to 4.   */ 

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;

        bool includeK = false;
        int balance = 0; 
        
        int ans = 0;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] < k)
                balance--;
            else if (nums[i] > k)
                balance++;
            else // nums[i] == k
                includeK = true;
            
            if (includeK)
              ans += mp[balance] + mp[balance - 1]; 
            
            else
                mp[balance]++;
        }
        return ans;         
    }
    
};