/*
Problem Statement:

You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
The graph is replented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
Return the length of the longest cycle in the graph. If no cycle exists, return -1.
A cycle is a path that starts and ends at the same node.

Approach: (DFS)

1. Create a variable 'l' to store the length of longest cycle and initialize to 1
2. Start from the First directed edge node and traverse using DFS till last edge
3. Traverse until you find a visited node or an end
4. While traversing assign each visited nodes to count-1
5. Check if cycle present in graph, if not found till end return l
6. If cycle present in graph, asssign 'l' to size of largest cycle.
7. Return 'l' after all nodes are visited.
*/

class Solution 
{
public:
    int longestCycle(vector<int>& edges) 
    {
        int l=-1,count=-2;
        for(int i=0; i<edges.size();++i) 
        {
            // Skip if dead end or visited node
            if (edges[i] < 0) continue;
            int cur = i, prev = i;
            int og_count = count;
            // Iterate until dead end or visited node
            while (edges[cur] >= 0) 
            {
                prev = cur;
                cur = edges[cur];
                edges[prev] = count--;
            }
            // Check if loop present
            if (edges[cur] <= og_count) 
            {
                l=max(l, edges[cur] - edges[prev] + 1);
            }
        }
        return l;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/