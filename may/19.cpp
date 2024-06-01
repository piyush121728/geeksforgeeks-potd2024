#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {
        // Complete the function
        int l = 0, r = n - 1;
        int left = 0;
        int right = INT_MAX;

        // cout << left << " " << right << endl;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (arr[mid] <= k)
            {
                left = max(arr[mid], left);
                l = mid + 1;
            }
            else
            {
                if (arr[mid] > k)
                {
                    right = min(arr[mid], right);
                }
                r = mid - 1;
            }
        }
        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (arr[mid] >= k)
            {
                right = min(arr[mid], right);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << left << " " << right << endl;
        int d1 = abs(left - k), d2 = abs(right - k);
        if (d1 < d2)
        {
            return left;
        }

        return right;
    }
};

// link : https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1