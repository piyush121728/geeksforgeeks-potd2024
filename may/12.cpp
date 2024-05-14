#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int d)
    {
        // code here
        long long i = 1;
        for (; i <= 2 * d; i++)
        {
            long long sum = (i * (i + 1)) / 2;
            if ((sum + d) % 2 == 0 && sum <= d)
            {
                break;
            }
        }

        return (int)i;
    }
};

// link : https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1