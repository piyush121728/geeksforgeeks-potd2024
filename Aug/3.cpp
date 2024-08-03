#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i != j && mat[i][j])
                {
                    mp[j].insert(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[i].size() == n - 1)
            {
                bool f = true;
                for (int j = 0; j < n; j++)
                {
                    if (mp[j].count(i))
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

// link : https://www.geeksforgeeks.org/problems/the-celebrity-problem/1