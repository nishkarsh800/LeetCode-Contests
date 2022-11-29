/* 
Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
*/
class Solution {
public:
    int pivotInteger(int n) 
    {
        //use prefix sum approach 
        vector<int> left(n+1);
        vector<int> right(n+1);
        
        int total = 0;
        
        for(int i=1;i<=n;i++)
        {
            total += i;
        } 
        //total comes out to be 36
        
        left[0] = 0;
        right[0] = 0;
        
        // during the loop runs, array status of left and right are : 
        // left : 0 1 3 6 10 15 21 28 36
        // right : 0 36 35 33 30 26 21 15 8
        // clearly, 21 at idx 6 in both the arrays matches. Hence return 6. 

        for(int i=1;i<=n;i++)
        {
            left[i] = i + left[i-1];
            right[i] = total - left[i-1];
            
            if(left[i]==right[i]) return i;
        }

        //if no element matches in both the arrays return -1 
        return -1;
    }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N) ; using two vectors left and right.