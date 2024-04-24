#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
private:
    vector<vector<int>> dp;
    int rec(int x, int y)
    {
        if (x == 0 && y == 0)
            return 1;

        if (x < 0 || y < 0)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        return dp[x][y] = (rec(x - 1, y) + rec(x, y - 1)) % 1000000007;
    }

public:
    int ways(int x, int y)
    {
        // code here.
        dp.clear();
        dp.resize(x + 1, vector<int>(y + 1, -1));

        return rec(x, y) % 1000000007;
    }
};