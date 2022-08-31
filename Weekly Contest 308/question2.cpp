/*
Problem Statement:

You are given a string s, which contains stars *.
In one operation, you can:
- Choose a star in s.
- Remove the closest non-star character to its left, as well as remove the star itself.

Return the string after all stars have been removed.

Example:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
    - The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
    - The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
    - The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
    There are no more stars, so we return "lecoe".

Approach (Stack Simulation) :

1. Use a stack to simulate the process of removing stars from a string.
2. For each character 'c' in string 's', do the following operations,
3. If c =='*', pop the last element from the stack, to simulate the deletion.
4. If c != '*', push the element to the stack.
5. Finally return the string with stars removed.

*/

class Solution 
{
public:
    string removeStars(string s) 
    {
        string res;
        for (char c : s)
        {
            if (c == '*')   // Removing element from the stack
            {
                res.pop_back();
            }
            else    // Inserting elements into stack
            {
                res += c;
            }
        }
        return res;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/