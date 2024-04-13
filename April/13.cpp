#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        vector<int> v(32, 0);
        int i = 0;
        while (x != 0)
        {
            if (x & 1)
            {
                v[i] = 1;
            }
            i++;
            x = x / 2;
        }

        reverse(v.begin(), v.end());

        for (int i = 0; i < 32; i++)
        {
            if (v[i] == 1)
            {
                long long sum = (1 << i);
                x = x + abs(sum);
            }
        }

        return abs(x);
    }
};