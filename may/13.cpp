#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &ver)
    {
        vis[src] = 1;
        ver.push_back(src);

        for (auto adjNode : adj[src])
        {
            if (!vis[adjNode])
            {
                dfs(adjNode, adj, vis, ver);
            }
        }
    }

    int findNumberOfGoodComponent(int e, int n, vector<vector<int>> &edges)
    {
        // code here
        vector<int> adj[n + 1];
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n + 1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vector<int> ver;
                dfs(i, adj, vis, ver);

                int m = ver.size();
                bool f = true;

                for (auto v : ver)
                {
                    if (adj[v].size() != m - 1)
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    res++;
                }
            }
        }
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1