#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<vector<long long>>> dp;

    long long solve(long long n, int k)
    {
        string s = bitset<64>(n).to_string();
        for (int i = 0; i < 65; i++)
        {
            for (int j = 0; j < 65; j++)
            {
                dp[0][i][j] = -1;
                dp[1][i][j] = -1;
            }
        }
        return rec(s, s.length(), 1, k);
    }

    long long rec(string &s, int n, int flag, int k)
    {
        if (k < 0)
            return 0;
        if (n == 0)
        {
            return 1;
        }
        if (dp[flag][k][n] != -1)
            return dp[flag][k][n];
        int mid = (flag == 1 ? s[s.length() - n] - '0' : 1);
        long long ans = 0;
        for (int dig = 0; dig <= mid; dig++)
        {
            if (dig == mid)
                ans += rec(s, n - 1, flag, k - dig);
            else
                ans += rec(s, n - 1, 0, k - dig);
        }
        return dp[flag][k][n] = ans;
    }
    long long findNthNumber(int n, int k)
    {
        long long low = 0, high = 1e18;
        dp.resize(2, vector<vector<long long>>(65, vector<long long>(65)));

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long count = solve(mid, k);
            if (count >= n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

// link : https://www.geeksforgeeks.org/problems/geekina-hate-1s/1