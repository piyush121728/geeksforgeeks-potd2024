#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void zigZag(int n, vector<int> &arr)
    {
        // code here
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 1 && arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
            else if (i % 2 == 0 && arr[i - 1] < arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
    }
};

// link : https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1