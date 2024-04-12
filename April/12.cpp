#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        // code here
        vector<long long> v(32, 0);
        for (int i = 0; i < n; i++)
        {
            long long x = arr[i];
            for (int j = 0; j < 32; j++)
            {
                if ((x >> j) & 1)
                {
                    v[j]++;
                }
            }
        }
        long long sum = 0;
        for (int i = 0; i < 32; i++)
        {
            if (v[i] > 0)
            {
                long long pairs = (v[i] * (v[i] - 1)) / 2;
                long long currSum = (1 << i) * pairs;
                sum += currSum;
            }
        }
        return sum;
    }
};

// link : https://www.geeksforgeeks.org/problems/sum-of-products5049/1