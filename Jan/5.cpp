#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1000000007;
    vector<long long> dp;
    long long rec(int i)
    {
        if (i < 0)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        long long notTake = rec(i - 1);
        long long take = rec(i - 2) + 1;

        return dp[i] = (take + notTake) % mod;
    }
    int TotalWays(int n)
    {
        // Code here
        dp.resize(n, -1);
        long long ans = 1 + rec(n - 1);
        return (ans * ans) % mod;
    }
};
int main()
{
    return 0;
}
// link : https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1