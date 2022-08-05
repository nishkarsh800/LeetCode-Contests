/**

Number of Distinct Roll Sequences

You are given an integer n. You roll a fair 6-sided dice n times. Determine the total number of distinct sequences of rolls possible such that the following conditions are satisfied:

The greatest common divisor of any adjacent values in the sequence is equal to 1.
There is at least a gap of 2 rolls between equal valued rolls. More formally, if the value of the ith roll is equal to the value of the jth roll, then abs(i - j) > 2.
Return the total number of distinct sequences possible. Since the answer may be very large, return it modulo 109 + 7.

Two sequences are considered distinct if at least one element is different.

 

Example 1:

Input: n = 4
Output: 184
Explanation: Some of the possible sequences are (1, 2, 3, 4), (6, 1, 2, 3), (1, 2, 3, 1), etc.
Some invalid sequences are (1, 2, 1, 3), (1, 2, 3, 6).
(1, 2, 1, 3) is invalid since the first and third roll have an equal value and abs(1 - 3) = 2 (i and j are 1-indexed).
(1, 2, 3, 6) is invalid since the greatest common divisor of 3 and 6 = 3.
There are a total of 184 distinct sequences possible, so we return 184.
Example 2:

Input: n = 2
Output: 22
Explanation: Some of the possible sequences are (1, 2), (2, 1), (3, 2).
Some invalid sequences are (3, 6), (2, 4) since the greatest common divisor is not equal to 1.
There are a total of 22 distinct sequences possible, so we return 22.
 

Constraints:

1 <= n <= 10^4
**/

/** 
Approach:

Now, what we see ,that we have choices for every indices:-
-->But we follow rules to fillis according to choices.
-->And when we will fill all indices then we will get one choice.

**⚫ Algorithm and steps:- **

-->Initillay We will create a 2d vector size 7.
-->Ignoring 0'th index.
-->All other i'th index vector will hold the list of all the numbers which will have gcd 1 with i.

-->We have all 6 choices to fix at index 0.
-->We will call a solve function:-
-->Solve function have three dp state variable :
  1.) idx:-Aindex on which we will put some choices from 1 to 6.
2.) Val:- value we have putted at index idx-1.
3.) PreVal:- value we have putted at index idx-2;

-->Base condition of solve:- if idx hit n then return 1.
-->Other wise for index idx we will Put values which are eligible for putting next of Val i.e thier gcd be 1 and it must not eual to PreVal.

-->Add all choices in ans1 and return it .

--> **Time Complexity:- ** O(6n);
--> **Sapce Complexity :- ** O(77n);

**/


// Here is the solution:
#define mod 1000000007
class Solution 
{
public:
    int dp[10001][7][7];
    int solve(int PreVal,int Val,int idx,int &n,vector<vector<int>>&v)
    {
        if(idx>=n) //Base Condition
            return 1;
        
        
        if(dp[idx][PreVal][Val]!=-1) //Memoization
            return dp[idx][PreVal][Val]%mod;
        
        
        int ans1=0; //Answer that will keep count.
        for(int i=0;i<v[Val].size();i++) //Check all the eligibale number for adjacent of Val.
        {
            
            if(PreVal!=v[Val][i]) //But it sholud not equal to PreVal.
            {
                /*Then call solve function for index idx+1.
                -->And val will become preval.
                -->Add it in ans1.*/
                ans1=(ans1 % mod + solve(Val,v[Val][i],idx+1,n,v) % mod)%mod; 
            }
            
        }
        
        return dp[idx][PreVal][Val] = ans1%mod; //return ans1
    }
    int distinctSequences(int n) 
    {
        vector<vector<int>>v(7); //2d vector that will store the Gcd 1 values with i'th index.
        
        v[1]={2,3,4,5,6};
        v[2]={1,3,5};
        v[3]={1,2,4,5};
        v[4]={1,3,5};
        v[5]={1,2,3,4,6};
        v[6]={1,5};
        
        memset(dp,-1,sizeof(dp)); 
        
        int ans=0;
        for(int i=1;i<=6;i++) //For index 0 we have all choices from 0 to 6.
        {
            ans=(ans % mod+solve(i,i,1,n,v) % mod)%mod; //Call solve function from index 1.
        }
        
        return ans%mod; // return ans.
    }
};