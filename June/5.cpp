#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        // Your code goes here
        unordered_map<int, int> mp;
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
        {
            s1 += a[i];
            mp[a[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            s2 += b[i];
        }

        long long z = s1 - s2;
        for (int i = 0; i < m; i++)
        {
            long long x2 = b[i] + b[i];
            long long x1 = z + x2;
            if (x1 % 2 == 0 && mp[x1 / 2] > 0)
            {
                return 1;
            }
        }

        return -1;
    }
};

// link : https://www.geeksforgeeks.org/problem-of-the-day?itm_source=geeksforgeeks&itm_medium=main_header&itm_campaign=practice_header