/*
Problem Statement:

You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.
You are also given two integers node1 and node2.
Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
Note that edges may contain cycles.

Approach: (DFS)

1. Create two unordered sets 'st' and 'tst'
2. Traverse from each of the node simultaneously, also identify the lower vlaue node and larger value node
3. Keep on storing the visited node in two different sets
4. Check for the occurence of first node in next set and second node in the first set
5. If found report answer, if not found till end then return -1
6. Also check for cycle, occurence of the node in the same set again. if found set it to -1 to terminate the loop.

*/

class Solution 
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        unordered_set<int> st, tst;
        int ptr = max(node1, node2);
        int tptr= min(node1, node2);
        while(ptr != -1 || tptr != -1)
        {
            if(st.find(ptr) != st.end()) ptr = -1;
            if(tst.find(tptr) != tst.end()) tptr = -1;
            st.insert(ptr);
            tst.insert(tptr);
            //  Important to check ptr first as smaller should be reported first in case of tie
            if(tst.find(ptr) != tst.end()) return ptr;  
            if(st.find(tptr) != st.end() ) return tptr;
            if(ptr != -1) ptr = edges[ptr];
            if(tptr != -1) tptr = edges[tptr];
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/