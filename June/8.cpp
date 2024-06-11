#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.
        int i = 0;
        for (; i < n; i++)
        {
            if (i == n - 1 || arr1[i] != arr2[i])
            {
                break;
            }
        }
        return i;
    }
};

// link : https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1