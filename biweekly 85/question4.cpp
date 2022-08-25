/**
2382. Maximum Segment Sum After Removals.

You are given two 0-indexed integer arrays nums and removeQueries, both of length n. For the ith query, the element in nums at the index removeQueries[i] is removed, splitting nums into different segments.

A segment is a contiguous sequence of positive integers in nums. A segment sum is the sum of every element in a segment.

Return an integer array answer, of length n, where answer[i] is the maximum segment sum after applying the ith removal.

Note: The same index will not be removed more than once.

Example 1:

Input: nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
Output: [14,7,2,2,0]
Explanation: Using 0 to indicate a removed element, the answer is as follows:
Query 1: Remove the 0th element, nums becomes [0,2,5,6,1] and the maximum segment sum is 14 for segment [2,5,6,1].
Query 2: Remove the 3rd element, nums becomes [0,2,5,0,1] and the maximum segment sum is 7 for segment [2,5].
Query 3: Remove the 2nd element, nums becomes [0,2,0,0,1] and the maximum segment sum is 2 for segment [2]. 
Query 4: Remove the 4th element, nums becomes [0,2,0,0,0] and the maximum segment sum is 2 for segment [2]. 
Query 5: Remove the 1st element, nums becomes [0,0,0,0,0] and the maximum segment sum is 0, since there are no segments.
Finally, we return [14,7,2,2,0].

Example 2:

Input: nums = [3,2,11,1], removeQueries = [3,2,1,0]
Output: [16,5,3,0]
Explanation: Using 0 to indicate a removed element, the answer is as follows:
Query 1: Remove the 3rd element, nums becomes [3,2,11,0] and the maximum segment sum is 16 for segment [3,2,11].
Query 2: Remove the 2nd element, nums becomes [3,2,0,0] and the maximum segment sum is 5 for segment [3,2].
Query 3: Remove the 1st element, nums becomes [3,0,0,0] and the maximum segment sum is 3 for segment [3].
Query 4: Remove the 0th element, nums becomes [0,0,0,0] and the maximum segment sum is 0, since there are no segments.
Finally, we return [16,5,3,0].
 

Constraints:
n == nums.length == removeQueries.length
1 <= n <= 105
1 <= nums[i] <= 109
0 <= removeQueries[i] < n
All the values of removeQueries are unique.**/



// Time Complexity is O(N)
// Space Complexity is O(N)





// Here is the Solution:

typedef long long ll;
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) 
    {
        int n=nums.size();
        vector<ll>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+nums[i];
        multiset<ll>Set;
        map<int,int>Map;
        Set.insert(prefix[n-1]),Map[0]=n-1;
        vector<ll>res;
        for(auto &x:removeQueries)
        {
            auto it=Map.lower_bound(x);
            int l=0,r=0;
            if(it==Map.end())
            {
                auto cur=*Map.rbegin();
                l=cur.first,r=cur.second;
            }
            else
            {
                if(it->first>x)it--;      // will update it-- only if it is greater than x
                l=it->first;
                r=it->second;
            }
            ll tot=prefix[r]-(l-1>=0 ? prefix[l-1] : 0);
            Set.erase(Set.find(tot));
            Map.erase(l);
            if((r-l)!=0)
            {
                if(l==x)Set.insert(prefix[r]-prefix[l]),Map[l+1]=r;
                else if(r==x)Set.insert(prefix[r-1]-(l-1>=0 ? prefix[l-1] : 0)),Map[l]=r-1;
                else
                {
                    Set.insert(prefix[x-1]-(l-1>=0 ? prefix[l-1] : 0)),Map[l]=x-1;
                    Set.insert(prefix[r]-prefix[x]),Map[x+1]=r;
                }
            }
            if(Set.size()>0)res.push_back(*Set.rbegin());
            else res.push_back(0);
        }
        return res;
    }
};
