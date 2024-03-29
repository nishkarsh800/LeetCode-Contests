/*
Calculate Amount Paid in Taxes.
You are given a 0-indexed 2D integer array brackets where brackets[i] = [upperi, percenti] means that the ith tax bracket has an upper bound of upperi and is taxed at a rate of percenti. The brackets are sorted by upper bound (i.e. upperi-1 < upperi for 0 < i < brackets.length).

Tax is calculated as follows:

The first upper0 dollars earned are taxed at a rate of percent0.
The next upper1 - upper0 dollars earned are taxed at a rate of percent1.
The next upper2 - upper1 dollars earned are taxed at a rate of percent2.
And so on.
You are given an integer income representing the amount of money you earned. Return the amount of money that you have to pay in taxes. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: brackets = [[3,50],[7,10],[12,25]], income = 10
Output: 2.65000
Explanation:
Based on your income, you have 3 dollars in the 1st tax bracket, 4 dollars in the 2nd tax bracket, and 3 dollars in the 3rd tax bracket.
The tax rate for the three tax brackets is 50%, 10%, and 25%, respectively.
In total, you pay $3 * 50% + $4 * 10% + $3 * 25% = $2.65 in taxes.
Example 2:

Input: brackets = [[1,0],[4,25],[5,50]], income = 2
Output: 0.25000
Explanation:
Based on your income, you have 1 dollar in the 1st tax bracket and 1 dollar in the 2nd tax bracket.
The tax rate for the two tax brackets is 0% and 25%, respectively.
In total, you pay $1 * 0% + $1 * 25% = $0.25 in taxes.
Example 3:

Input: brackets = [[2,50]], income = 0
Output: 0.00000
Explanation:
You have no income to tax, so you have to pay a total of $0 in taxes.
 

Constraints:

1 <= brackets.length <= 100
1 <= upperi <= 1000
0 <= percenti <= 100
0 <= income <= 1000
upperi is sorted in ascending order.
All the values of upperi are unique.
The upper bound of the last tax bracket is greater than or equal to income.

*/

// Here is the Solution:

class Solution 
{
public:
    double calculateTax(vector<vector<int>>& brackets, int income)
    {
        if(!income) //If income is 0
            return 0;
        
        double ans(0.0);
        
        int i(0), prev(0);
        while(income)
        { //While income is not 0..
            int cur = brackets[i][0] - prev;
            //This gets the difference between current upper bound and previous upper bound
            
            ans += double(brackets[i][1]) / 100.0 * min(cur, income);
            //It's important to convert to double and divide by 100.0 because
            //if we stay with int, for example int 50 / int 100 ends up being 0 which is not accurate.
            
            income -= min(cur, income);
            //Using min because if there is still more income left for the next bracket,
            //then only minus the cur (which is the max amount that can be taxed for this bracket).
            //If income is less than cur, then this is the last bracket,
            //so tax and minus the income left. Then income = 0 and while loop ends.
            
            prev = brackets[i][0]; //Saving current upper bound
            i++; //Moving on to next bracket
        }
        
        return ans;
        
    }
};
