#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &arr, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
        return arr[i][j] > 0 ? 1 : -arr[i][j] + 1;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int res = INT_MAX;

    if (i + 1 < n)
    {

        res = min(res, -arr[i][j] + dfs(i + 1, j, arr, n, m, dp));
    }
    if (j + 1 < m)
    {
        res = min(res, -arr[i][j] + dfs(i, j + 1, arr, n, m, dp));
    }

    return dp[i][j] = res <= 0 ? 1 : res;
}
int minPoints(int n, int m, vector<vector<int>> points)
{
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return dfs(0, 0, points, n, m, dp);
}

// link : https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1