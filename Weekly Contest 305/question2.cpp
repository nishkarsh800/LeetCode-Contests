/*
Problem Statement:

There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. 
You are also given an integer array restricted which represents restricted nodes.
Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
Note that node 0 will not be a restricted node.

Approach: (BFS Traversal Algorithm)

1. First we need to create an undirected graph by connecting given edges.
2. Also insert all restricted nodes into a set for fast lookups.
3. Then in next step simply do a BFS over the graph starting from source = 0.
4. And whenever we reach a node that is unrestricted and which is not already visited, increment count by 1.

*/


class Solution 
{
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        vector<vector<int>> adj(n);  // Adjacency Matrix to represent graph
		// Create an undirected graph
        for(auto& edge : edges) 
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
		// Store all restricted nodes in a set for fast lookup
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());
		// Keep track of Visited nodes
        vector<bool> visited(n, false);
		// Queue to perform BFS
        queue<int> que;
		int source = 0;
        que.push(source);  // Add first element source into our queue
        int count = 0;  // To keep track of all reachable unrestricted nodes
		
		// Perform BFS
        while(que.size()) 
        {    
            int node = que.front(); que.pop();   
            visited[node] = true;  //Mark current node as visited
			// If current node is not restricted then only move further 
            if(restrictedSet.find(node) == restrictedSet.end()) 
            {
                count++;  // Increment count of reachable nodes
                
				// Iterate over all adjacent nodes and add them into queue 
				// And only insert if it is not visited and unrestricted
                for(auto& adjacentNode : adj[node]) 
                {
                    if(!visited[adjacentNode] && restrictedSet.find(adjacentNode) == restrictedSet.end()) 
                    {
                        que.push(adjacentNode);
                    }
                }
            }
        }
        
        return count;
    }
};

/*
Time Complexity: O(n*log(n)))
Space Complexity: O(n)
*/