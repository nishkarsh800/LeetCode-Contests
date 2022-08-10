/*
Problem Statement:

You are given a non-negative integer array nums. In one operation, you must:
- Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
- Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0

Approach: (Greedy Algorithm)

1. Create an unordered set and insert elements not present in it. 
2. If the set contains 0 return size of the set
3. Else return the size of set subracted by 1
*/

class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        unordered_set<int> s;  // Create an unordered set
        for (int i=0;i<nums.size();i++) 
        {
            if (s.find(nums[i])==s.end()) 
            {
                s.insert(nums[i]);  // Insert elements into set if element does not exist
            }
        }
        // if 0 found in set return size of set else return size-1
        if (s.find(0)!=s.end()) return s.size()-1;  
        else return s.size();
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/