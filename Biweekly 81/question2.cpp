/**

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.


Constraints:

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.


Approach:

Given the size of the maximum graph we can get, it seems clear that we need to be performance-conscious and thus the awesome magic of union-find (AKA "disjoint sets") can come to the rescue 💪

In order to proceed, we will start declaring this class (UF) first of all, with two class variables:

parent will store the parent of each node, initially set to be the node itself in the constructor;
rank will store the parent of each node, initially set to be the only 1 for each node in the constructor.
The find operation will recursively look for a parent of any node we want to check and write it down in parent[node], with our end case being when parent[node] ==node`, which demarks either a single node alone or the top parent of a given cluster.

The union operation is a bit more complex, and built on top of that; for each values x and y we will store in px and py respectively the value of their parents. We will then:

return out of the function if px == py, which means the two elements are already in the same cluster;
check if the first element is in a bigger cluster (rank[px] > rank[py]) and in that case, we will:
reparent py to point to px as his parent;
add rank[py] to rank[px];
otherwise:
reparent px to point to py as his parent;
add rank[px] to `rank[py].
The extra helper method findConnectes will take a node and return us the rank of its parent (found recursively through parent(node), as usual).

In our main function, we will instatiate a new UF object in uf, with capacity n and then populate it with every single edge in edges, calling union on each pair of points connected (edge[0] and edge[1]).

We have now a fully formed and clustered graph, so we will go through each node i from 0 to n (excluded) and:

compute how big is its cluster with uf.findConnected(i);
increase res by n - that number (since if we have overall n nodes and we know this cluster is made of uf.findConnected(i), then we can infer that all the others are not connected to i).
Notice that this way we would count each missing edge twice (ie: [0, 5] and [5, 0] will be both counted), so we ultimately have to return half the value of res (ie: res / 2 or, why not, res >> 1).

**/

// Time Complexity: O(N)
// Space Complexity: O(N)



class UF 
{
    // support variables
    int *parent, *rank;
public:
    UF(int n) 
    {
        // preparing parent and rank
        parent = new int[n];
        iota(parent, parent + n, 0);
        rank = new int[n];
        fill(rank, rank + n, 1);
    }
    int find(int node) 
    {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    void unite(int x, int y) 
    {
        int px = find(x), py = find(y);
        // already united
        if (px == py) return;
        // attaching elements to the biggest cluster
        if (rank[px] > rank[py]) {
            parent[py] = px;
            rank[px] += rank[py];
        }
        else 
        {
            parent[px] = py;
            rank[py] += rank[px];
        }
    }
    int findConnected(int node) 
    {
        return rank[find(node)];
    }
};

class Solution 
{
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        // support variables
        UF uf = UF(n);
        long long res = 0;
        // populating uf
        for (auto &edge: edges) 
        {
            uf.unite(edge[0], edge[1]);
        }
        // computing res
        for (int i = 0; i < n; i++) 
        {
            res += n - uf.findConnected(i);
        }
        return res >> 1;
    }
};
