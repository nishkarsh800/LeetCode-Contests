/*
Problem Statement:

You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. 
- garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. 
- Picking up one unit of any type of garbage takes 1 minute.
- You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.
- There are three garbage trucks in the city, each responsible for picking up one type of garbage. 
- Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.
- Only one garbage truck may be used at any given moment. 
- While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.

Example:

Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
    The paper garbage truck:
        1. Travels from house 0 to house 1
        2. Collects the paper garbage at house 1
        3. Travels from house 1 to house 2
        4. Collects the paper garbage at house 2
    Altogether, it takes 8 minutes to pick up all the paper garbage.
    The glass garbage truck:
        1. Collects the glass garbage at house 0
        2. Travels from house 0 to house 1
        3. Travels from house 1 to house 2
        4. Collects the glass garbage at house 2
        5. Travels from house 2 to house 3
        6. Collects the glass garbage at house 3
    Altogether, it takes 13 minutes to pick up all the glass garbage.
    Since there is no metal garbage, we do not need to consider the metal garbage truck.
    Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.

Approach (Prefix Sum):

1. Firstly sum up the amount of gabages in total.
2. Second find up the last position for each type.
3. Calculate the prefix sum array of the travel distance.
4. Sum up the distance for each type of garbage.
5. Finally return the minimum time required.

*/

class Solution 
{
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int last[128] = {}, res = 0;
        for (int i = 0; i < garbage.size(); ++i) 
        {
            res += garbage[i].size();
            for (char c : garbage[i])
                last[c] = i;
        }
        for (int j = 1; j < travel.size(); ++j)
        {
            travel[j] += travel[j - 1];
        }
        for (int c : "PGM")
        {
            if (last[c])
            {
                res += travel[last[c] - 1];
            }
        return res;
        }
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/