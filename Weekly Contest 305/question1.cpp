/*
Problem Statement:

You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. 
A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
- i < j < k,
- nums[j]-nums[i]==diff
- nums[k]-nums[j]==diff

Return the number of unique arithmetic triplets.

Approach: (Brute Force Approach)

1. Traverse through all elements in vector one by one
2. If the difference between two elements equal to 'diff', go to step 3.
3. Search for element with difference 'diff' from remaining elements.
4. If found increment the number of triplets found.

*/

class Solution 
{
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        int sum=0,flag,l=nums.size();
        for(int i=0;i<l;i++)
        {
            flag=0; // Set a flag to break loop when necessary
            for(int j=i+1;j<l;j++)
            {
                if ((nums[i]+diff)==nums[j]) // Check If difference between nums[i] and nums[j] equal to 'diff'
                {
                    for(int k=j+1;k<l;k++)
                    {
                        if ((nums[j]+diff)==nums[k]) // Check If difference between nums[j] and nums[k] equal to 'diff'
                        {
                            sum+=1; // Increment number of triplets by 1
                            flag=1;
                            break;
                        }
                    }
                    if (flag) break; // Flag==1 which means no triplets exist in this loop
                }
            }
        }
        return sum;
    }
};


/*
Time Complexity: O(n)
Space Complexity: O(n)
*/