#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &arr, int a, int b)
    {
        // code here
        int n = arr.size();
        int l = 0, r = n - 1, i = 0;
        while (i <= r)
        {
            if (arr[i] < a)
            {
                swap(arr[i], arr[l]);
                l++;
            }

            else if (arr[i] > b)
            {
                swap(arr[i], arr[r]);
                r--;
                i--;
            }

            i++;
        }
    }
};

// link : https://www.geeksforgeeks.org/problems/three-way-partitioning/1