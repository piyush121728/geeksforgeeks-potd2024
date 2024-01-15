#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int ind, int n, int total, vector<int> &cost, vector<vector<int>> &dp)
    {
        if (total <= 0)
            return 0;

        if (ind == n)
            return 0;

        if (dp[ind][total] != -1)
            return dp[ind][total];

        int notTake = solve(ind + 1, n, total, cost, dp);
        int take = 0;

        if (cost[ind] <= total)
            take = 1 + solve(ind + 1, n, total - cost[ind] + (0.9 * cost[ind]), cost, dp);

        return dp[ind][total] = max(take, notTake);
    }

    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return solve(0, n, total, cost, dp);
    }
};

int main()
{
    float f = 10 - ((9 / 10.0) * 8);
    cout << f << endl;
}

// link :https://www.geeksforgeeks.org/problems/grinding-geek/1