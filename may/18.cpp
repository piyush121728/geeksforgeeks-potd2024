#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &a)
    {
        // Code here.
        int n = a.size();
        int l = 0, r = n - 1;
        int maxi = 0;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (mid + 1 < n)
            {
                if (mid + 1 < n && a[mid + 1] > a[mid])
                {
                    l = mid + 1;
                }
                else if (mid + 1 < n)
                {
                    r = mid - 1;
                }
            }
            maxi = max(a[mid], maxi);
        }
        if (l == r)
        {
            maxi = max(a[l], maxi);
        }
        return maxi;
    }
};

// link : https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1