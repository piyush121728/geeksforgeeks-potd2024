#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    int dp[101][101];
    int rec(int i, int j, string s, string t)
    {
        if (i == n)
        {
            return m - j;
        }
        if (j == m)
        {
            return n - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return rec(i + 1, j + 1, s, t);
        }
        int ins = rec(i, j + 1, s, t) + 1;
        int upd = rec(i + 1, j + 1, s, t) + 1;
        int del = rec(i + 1, j, s, t) + 1;

        return dp[i][j] = min({ins, upd, del});
    }
    int editDistance(string s, string t)
    {
        // Code here
        n = s.size(), m = t.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, s, t);
    }
};

// link : https://www.geeksforgeeks.org/problems/edit-distance3702/1