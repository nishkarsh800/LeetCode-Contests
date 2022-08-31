/*
Problem Statement:

You are given a positive integer k. You are also given:
- A 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
- A 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].

The two arrays contain integers from 1 to k.
You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:
- The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
- The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.

Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.
 
Example:

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation:
The row conditions are the following:
    - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
    - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
    - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
    - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.


Approach (Topological Sorting and Kahn's Algorithm):

1. Create graph for both 'rowConditions' and 'colConditions'.
2. Check if both graphs are acyclic using Kahn's Algorithm. If either graph is cyclic, then return [].
3. Kahn's Algorithm will give topological sorting (topo1 and topo2) for both graphs.
4. 'topo1' will give position of element according to row.
5. 'topo2' will give position of element according to column.
6. Return Matrix 'ans' if satisfies given conditions else return [].

*/

class graph
{
    int n;
    vector<vector<int>> adj;
public:
    graph(int n)
    {
        this->n = n;
        adj.resize(n);
    }
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void make_adj(vector<vector<int>> arr)
    {
        for(auto& x:arr)
        {
            this->add_edge(x[0], x[1]);
        }
    }
    
    vector<int> kahn_algo()
    {
        vector<int> indeg(this->n, 0);
        queue<int> q;
        vector<int> topo;
        
        for(auto &x : this->adj)
        {
            for(int &y: x)
            {
                indeg[y]++;
            } 
        }

        for(int i=1; i<this->n; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            topo.push_back(cur);
            
            for(auto& x : this->adj[cur])
            {
                indeg[x]--;
                if(indeg[x] == 0)
                    {
                    q.push(x);
                }
            }
        }
        return topo;
    }
};

class Solution 
{
public:
    vector<vector<int>> solve(int& n, vector<int>& topo1, vector<int>& topo2)
    {
        if(topo1.size() != n || topo2.size() != n)
        {
            return {};
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        unordered_map<int, int> mp;
        for(int i=0; i<topo1.size(); i++)
        {
            mp[topo1[i]] = i;
        }
        for(int i=0; i<topo2.size(); i++)
        {
            ans[mp[topo2[i]]][i] = topo2[i];
        }
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int n, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        graph g1(n+1), g2(n+1);
        g1.make_adj(rowConditions);
        g2.make_adj(colConditions);
        vector<int> topo1 = g1.kahn_algo(), topo2 = g2.kahn_algo();
        return solve(n, topo1, topo2);        
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/