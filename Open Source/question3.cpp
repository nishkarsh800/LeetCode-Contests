/**
2381. Shifting Letters II
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied. 

Example 1:
Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

Example 2:
Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 
Constraints:
1 <= s.length, shifts.length <= 5 * 104
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.


// Time Complexity is O(N)
// Space Complexity is O(N)





// Here is the Solution:

class Solution {
public:
string shiftingLetters(string s, vector<vector>& shifts) {

    int size=s.size();
    vector<int> vec(size+1);
    for(auto it:shifts){
        int start=it[0],end=it[1],dir=it[2];
        if(dir==1)                  // checking for 1 and updating as desired
        {            
            vec[start]+=1;
            vec[end+1]+=-1;
        }
        else 
        {
            vec[start]+=-1;
            vec[end+1]+=1;
        }
    }
    int prefixSum=0;
    for(int i=0;i<size;i++)
    {
        prefixSum+=vec[i];
        while(prefixSum<0)
            prefixSum+=26;
        s[i]=(char)('a'+(((s[i]-'a')+prefixSum)%26));
    }   
    return s;
}
};