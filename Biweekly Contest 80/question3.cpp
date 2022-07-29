/*
You are given two strings s and sub. You are also given a 2D character array mappings
where mappings[i] = [oldi, newi] indicates that you may perform the following operation any number of times:
Replace a character oldi of sub with newi.
Each character in sub cannot be replaced more than once.
Return true if it is possible to make sub a substring of s by replacing zero or more characters according to mappings.
Otherwise, return false.
A substring is a contiguous non-empty sequence of characters within a string.

Approach :
1. Convert a new mapping 'New' where key is the old character which stores a set of new characters.
2. This will help to find in O(1) if there is any character 'new' that can be replaced for any character 'old'
3. Let n be the length of s and m be the length of sub.
4. Simply loop through each substring of length m in string s and check,
5. Simply continue if the character matches.
6. In the absence of a match, see whether we can convert to a character using an unordered map.
7. Continue if we can effect change.
8. Else, it is not feasible for that substring.

*/

class Solution
{
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings)
    {
        unordered_map<char, unordered_set<char>> New;
        int n = s.size(), m = sub.size();
        for(int i = 0; i < mappings.size(); i++)
        {
            New[mappings[i][0]].insert(mappings[i][1]);
        }
        for(int i = 0; i < n - m + 1; i++)
        {
            for(int j = i; j < i + m; j++)
            {
                if(s[j] == sub[j - i] || New[sub[j - i]].find(s[j]) != New[sub[j - i]].end())
                {
                    if(j == i + m - 1) return true;
                } else break;
            }
        }
        return false;
    }
};

// Time complexity: O(n * m) where size(s) = n & size(sub) = m
