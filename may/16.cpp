#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;
    int dfs(int src, vector<bool> &vis, vector<int> adj[])
    {
        vis[src] = true;
        int count = 1;
        for (auto adjNode : adj[src])
        {
            if (!vis[adjNode])
            {
                int res = dfs(adjNode, vis, adj);
                if (res % 2 == 0)
                {
                    ans++;
                }
                else
                {
                    count += res;
                }
            }
        }
        return count;
    }

public:
    int minimumEdgeRemove(int n, vector<vector<int>> edges)
    {
        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n + 1, false);
        dfs(1, vis, adj);
        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/divisibility-tree1902/1