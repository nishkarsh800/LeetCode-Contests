/*
You are given two positive integer arrays spells and potions, of length n and m respectively,
where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
You are also given an integer success.
A spell and potion pair is considered successful if the product of their strengths is at least success.
Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

Approach :(Sorting and Binary Search)
1. Sorting potions so that binary search can be applied on it
2. For every spell, binary search on the number of potions that can be used such that spells[i] * potions[j] >= success.
3. If any particular potion satisfies the above condition, then all the potions from potions[mid] to potions[m - 1] should satisfy the condition as well.
4. Hence, we now store this index in 'c' and proceed to find if any lower index in potions satisfy the condition or not.
5. If condition is not satisfied, proceed to a higher index.
6. Now if all potions from potions[c] to potions[m - 1] satisfy the condition, we have 'm - c' pairs for this particular spell.

*/

class Solution
{
public:
    // Sorting and Binary Search
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        int n = spells.size(), m = potions.size();
        //sorting potions
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int i = 0; i < n; i++)
            {
            int l = 0, r = m - 1, c = m;
            while(l <= r)
                {
                int mid = l + (r - l) / 2;
                if((((long long)potions[mid]) * ((long long)spells[i])) >= success)
                {
                    c = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans.push_back(m - c);
            }
        return ans;
    }
};

/*
Time Complexity= O(m log m)+ O(n log m)
Space Complexity : O(m)
*/
