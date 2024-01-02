#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> dp;
    void kadanesAlgo(long long int v[], long long int n)
    {
        long long currSum = v[0], maxSum = v[0];

        dp.resize(n, 0);
        dp[0] = maxSum;

        for (long long int i = 1; i < n; i++)
        {
            if (currSum < 0)
            {
                currSum = v[i];
            }
            else
            {
                currSum += v[i];
            }
            maxSum = max(maxSum, currSum);
            dp[i] = currSum;
        }
    }

    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        kadanesAlgo(a, n);

        long long int maxi = 0, j = 0;

        long long int currSum = 0;

        for (long long int i = 0; i < k; i++)
        {
            currSum += a[i];
        }

        maxi = currSum;

        long long int i = k;

        for (long long int i = k; i < n; i++)
        {
            currSum -= a[j];
            j++;
            currSum += a[i];
            maxi = max({maxi, currSum, currSum + dp[j - 1]});
        }

        return maxi;
    }
};

int main()
{
    return 0;
}