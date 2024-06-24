#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        // code here
        if (q < 2 || q > 2 * n)
        {
            return 0;
        }
        else if (q <= n)
        {
            return q - 1;
        }

        return n - (q - n - 1);
    }
};

// link : https://www.geeksforgeeks.org/problems/summed-matrix5834/1