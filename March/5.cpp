#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TLE : 1120 / 1121
    /*
    int maxIndexDiff(int a[], int n)
    {
        int i = 0, j = n - 1, maxi = -1;

        while (i <= j)
        {
            if (a[i] <= a[j])
            {
                maxi = max(maxi, j - i);
                i++;
                j = n - 1;
            }
            else
            {
                j--;
            }
        }

        return maxi;
    }
    */
    int maxIndexDiff(int a[], int n)
    {
        vector<int> prefixMin(n, 0), suffixMax(n, 0);

        prefixMin[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[prefixMin[i - 1]])
            {
                prefixMin[i] = i;
            }
            else
            {
                prefixMin[i] = prefixMin[i - 1];
            }
        }

        suffixMax[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[suffixMax[i + 1]])
            {
                suffixMax[i] = i;
            }
            else
            {
                suffixMax[i] = suffixMax[i + 1];
            }
        }

        int i = 0, j = 0, res = 0;
        while (i < n && j < n)
        {
            if (a[prefixMin[i]] <= a[suffixMax[j]])
            {
                res = max(res, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }

        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1