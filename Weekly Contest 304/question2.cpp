/*
Problem Statement:

You are given a positive integer array grades which represents the grades of students in a university. You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:
- The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
- The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
Return the maximum number of groups that can be formed.

Approach: (Greedy Algorithm)

1. Sort the given vector in ascending order
2. Create a vector 'a' and iterator 'it' pointing begin of vector 'grades'
3. Create while loop and iterate loop until 'it' reaches end of vector
4. Create variables 'k' & 'c' to store total groups and sum of each group respectively 
5. Pop elements from vector and push into 'a' until its sum greater than previous group
6. If k is greater than size of vector 'a', increment 'k' and 'it' by 1
7. Repeat steps 4,5,6 until 'it' reaches end of vector 'grades'
8. Return 'k' the number of groups.
*/


class Solution 
{
public:
    int maximumGroups(vector<int>& grades) 
    {
        sort(grades.begin(),grades.end());  // Sorting given vector
        int c=0,k=0;
        vector<int> a;
        vector<int>::iterator it=grades.begin();
        while(it!=grades.end())
        {
            int flag=1,sum=accumulate(a.begin(), a.end(), 0);
            while (sum<=c || a.size()<=k)
            {
                if (it!=grades.end())
                {
                    a.push_back(*it);   
                    sum+=*it;
                    it++;
                } 
                else
                {
                    flag=0; // Setting flag, inorder to reset vector a and increment k
                    break;
                }
            }
            if (flag)
            {
                // resetting variables to inital values
                c=accumulate(a.begin(), a.end(), 0);
                a.clear();
                k+=1;     
                continue;
            }
        }
        return k;
    }
};

/*
Time Complexity: O(n*log(n)))
Space Complexity: O(n)
*/