#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for (int i = 0; i < n; i++)
        {
            int l = (2 * i) + 1, r = (2 * i) + 2;

            if (l < n && arr[l] > arr[i])
            {
                return false;
            }

            if (r < n && arr[r] > arr[i])
            {
                return false;
            }
        }

        return true;
    }
};

// link : https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
