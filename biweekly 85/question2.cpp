/**
2380. Time Needed to Rearrange a Binary String

You are given a binary string s. In one second, all occurrences of "01" are simultaneously replaced with "10". This process repeats until no occurrences of "01" exist.

Return the number of seconds needed to complete this process.
 
Example 1:
Input: s = "0110101"
Output: 4
Explanation: 
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.

Example 2:
Input: s = "11100"
Output: 0
Explanation:
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.
 
Constraints:
1 <= s.length <= 1000
s[i] is either '0' or '1'
**/



// Time Complexity is O(N)
// Space Complexity is O(N)





// Here is the Solution:

int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int one = count(s.begin(), s.end(), '1');
        int i = 0;
        int swap = 0;
        while(one){//place a '1' at the index i and reduce one's count and increase i, and place another '1' there and so on, till there is no 'one' left
            if(s[i] == '1'){ //if i'th index has already '1', then reduce one's count and update i to next index
                one--;
                i++;
            }else{//swap all possible "01" to "10" and increase swap count, don't reduce one's count, casue we don't know s[i] == '1' or not
                for(int j = i; j < n-1; j++){
                    if(s[j] == '0' && s[j+1] == '1'){
                        s[j] = '1';
                        s[j+1] = '0';
                        j++;
                    }
                }
                swap++;
            }
        }
        return swap;
    }
