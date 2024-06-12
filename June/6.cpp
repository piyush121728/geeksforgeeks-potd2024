#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long max_sum(int a[], int n)
    {
        // Your code here
        long long ps = 0, s = 0, maxi = 0;
        for (long long i = 0; i < n; i++)
        {
            ps += (i * (long long)a[i]);
            s += a[i];
        }
        maxi = ps;

        for (long long i = 1; i < n; i++)
        {
            long long cs = ps - (s - a[i - 1]) + (long)a[i - 1] * (n - 1);
            maxi = max(maxi, cs);
            ps = cs;
        }

        return maxi;
    }
};

// link : https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1