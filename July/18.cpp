#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int rec(int i, bool f, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            return 1;
        }

        if (dp[i][f] != -1)
        {
            return dp[i][f];
        }

        int notTake = rec(i + 1, f, arr, dp);
        int take = 0;
        if (f == 1 && arr[i + 1] < arr[i])
        {
            take = rec(i + 1, !f, arr, dp) + 1;
        }
        else if (f == 0 && arr[i + 1] > arr[i])
        {
            take = rec(i + 1, !f, arr, dp) + 1;
        }

        return dp[i][f] = max(take, notTake);
    }

    int alternatingMaxLength(vector<int> &arr)
    {
        // Code here
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return max(rec(0, 0, arr, dp), rec(0, 1, arr, dp));
    }
};

// link : https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1