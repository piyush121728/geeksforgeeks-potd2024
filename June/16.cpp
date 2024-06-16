#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getPrimes(int n)
    {
        // code here
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        prime[0] = 0;
        prime[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            if (prime[i] && prime[n - i])
            {
                return {i, n - i};
            }
        }

        return {-1, -1};
    }
};

// link : https://www.geeksforgeeks.org/problems/sum-of-prime4751/1