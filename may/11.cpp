#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> jugglerSequence(long long n)
    {
        // code here
        vector<long long> ans;
        while (n > 1)
        {
            ans.push_back(n);
            if (n & 1)
            {
                n = pow(n, 1.5);
            }
            else
            {
                n = pow(n, 0.5);
            }
        }
        ans.push_back(n);
        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/juggler-sequence3930/1