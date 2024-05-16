#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    // intial configuration
    vector<int> parent, rank, size; // parent->to store the ultimate parent of ith node and rank->to store the rank of ith node

    // constructor
    // Both for O based vertices or 1 based vertices
    DisjointSet(int n) // n->number of vertices
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // function to find the ultimate parent of a node

    /*
    //This function find ultimate partent of a node in O(log n)
    int findUPar(int node)
    {
        //base case;
        if(node==parent[node])
        {
            return node;
        }

        //induction hypothesis
        return findUPar(parent[node]);
    }
    */

    // In order to reduce the time complextiy of findUPar we can apply path compression technique on it
    // which will take O(const) to find the ultimate parent of a node
    // TC : O(4 alpha) = O(1)
    //  SC : O(1)
    int findUPar(int node)
    {
        // base case;
        if (node == parent[node])
        {
            return node;
        }

        // induction hypothesis
        return parent[node] = findUPar(parent[node]);
    }

    // union by rank
    // TC : O(4 alpha) + O(4 alpha) = O(1)
    // SC : O(1)

    void unionByRank(int u, int v)
    {
        // step 1 : find the ultimate parent of u and v
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        // when both ulp_u and ulp_v belong to same parent(same compo) then we simply return
        if (ulp_u == ulp_v)
        {
            return;
        }

        // step 2 : find the rank of ulp_u and ulp_v
        int ulp_u_r = rank[ulp_u], ulp_v_r = rank[ulp_v];

        // step 3 : connect the smaller rank to the larger rank always
        if (ulp_u_r < ulp_v_r)
        {
            parent[ulp_u] = ulp_v;
        }
        else if (ulp_u_r > ulp_v_r)
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // if ulp_u_r and ulp_v_r are same, then we can connect either ulp_u_r to ulp_v_r or ulp_v_r to ulp_u_r
            parent[ulp_v] = ulp_u;
            // In this case, we need to increase the rank by one because ulp_u_r and ulp_v_r are same,
            // if we connect either ulp_u_r to ulp_v_r or ulp_v_r to ulp_u_r then height of either ulp_v_r and ulp_u_r will be increase by one respectively
            rank[ulp_u]++;
        }
    }

    // union by size
    // TC : O(4 alpha) + O(4 alpha) = O(1)
    // SC : O(1)
    void unionBySize(int u, int v)
    {
        // step 1 : find the ultimate parent of u and v
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        // when both ulp_u and ulp_v belong to same parent(same compo) then we simply return
        if (ulp_u == ulp_v)
        {
            return;
        }
        // step 2 : find the size of ulp_u and ulp_v
        int ulp_u_s = size[ulp_u], ulp_v_s = size[ulp_v];

        // step 3 : connect the smaller size to the larger size always
        if (ulp_u_s < ulp_v_s)
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details)
    {
        // code here
        // step 1:
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            int m = details[i].size();

            for (int j = 1; j < m; j++)
            {
                string mail = details[i][j];
                // when email is already present in mp
                if (mp.find(mail) == mp.end())
                {
                    mp.insert({mail, i});
                }
                else
                {
                    int u = i;
                    int v = mp[mail];
                    ds.unionByRank(v, u);
                }
            }
        }

        // step 2:
        vector<string> mergedMail[n];
        for (auto it : mp)
        {
            string mail = it.first;
            int index = ds.findUPar(it.second);
            mergedMail[index].push_back(mail);
        }

        // step3.
        vector<vector<string>> output;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
            {
                continue;
                ;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            string name = details[i][0];
            temp.push_back(name);
            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            output.push_back(temp);
        }
        sort(output.begin(), output.end(), greater<vector<string>>());
        return output;
    }
};

// link : https://www.geeksforgeeks.org/problems/account-merge/1