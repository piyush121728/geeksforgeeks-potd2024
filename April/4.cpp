#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {
        int n = s.size();
        long long mod = 1e9 + 7;
        long long prev = 0, curr = 0, res = 0;

        for (int i = 0; i < n; i++)
        {
            curr = ((i + 1) * (s[i] - '0')) + (10 * prev);
            curr %= mod;
            res += curr;
            res %= mod;
            prev = curr;
        }

        return res;
        ;
    }
};

// link : https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1