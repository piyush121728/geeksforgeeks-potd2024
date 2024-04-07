#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int rec(int i, int j, int cnt, int a[], int b[], int n, int m, vector<vector<int>> &dp)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MIN;
        if (cnt > 0)
        {
            ans = max(ans, rec(i + 1, j, cnt - 1, a, b, n, m, dp));
        }

        ans = max(ans, rec(i + 1, j + 1, cnt, a, b, n, m, dp) + a[i] * b[j]);

        return dp[i][j] = ans;
    }

    int maxDotProduct(int n, int m, int a[], int b[])
    {
        // Your code goes here
        int cnt = n - m;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(0, 0, cnt, a, b, n, m, dp);
    }
};

// link : https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1
