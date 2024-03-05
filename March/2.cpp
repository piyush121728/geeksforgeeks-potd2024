#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstElementKTime(int n, int k, int a[])
    {
        map<int, int> mp;
        int res = -1;

        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            if (mp[a[i]] == k)
            {
                res = a[i];
                break;
            }
        }

        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1