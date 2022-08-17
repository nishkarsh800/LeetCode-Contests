/*
Problem Statement:

You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
    1. t is a subsequence of the string s.
    2. The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.

Return the length of the longest ideal string.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.


Approach: (Dynammic Programmming)

1. Iterate from every character in the string from left to right name this iterator 'ch'
2. For every 'ch' there is some index int(ch - 'a') in the DP array say it 'i'
3. For every 'j' from max(0, i - k) to min(25, i + k), assign DP[i] = max(DP[i], DP[j] + 1)
4. Every character that ends with character 'j' that can be used to append this character 'i', with maximum 1 + DP[j] length.
5. The case when j==i should be taken separately because it might happen that it appear earlier and you might modify it several times.

*/

class Solution 
{
public:
    int longestIdealString(string s, int k) 
    {
        int DP[26] = {0}, ans = 1;
        for (char &ch: s) 
        {
            int i = ch - 'a';
            DP[i] = DP[i] + 1;
            for (int j = max(0, i - k); j <= min(25, i + k); j++)
            {
                if (j != i)
                {
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
            ans = max(ans, DP[i]);
        }       
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(128)
*/