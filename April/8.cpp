#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long rec(int i, int j, int turn, int arr[], vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        long long ans = 0;
        if (turn == 0)
        {
            ans = max({ans, arr[i] + rec(i + 1, j, 1, arr, dp), arr[j] + rec(i, j - 1, 1, arr, dp)});
        }
        else
        {
            ans = min(rec(i + 1, j, 0, arr, dp), rec(i, j - 1, 0, arr, dp));
        }
        return dp[i][j] = ans;
    }
    long long maximumAmount(int n, int arr[])
    {
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, n - 1, 0, arr, dp);
    }
};

// link : https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1