#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        if (x == 0)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] == arr[i + 1])
                {
                    return 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int y = arr[i] + x;
                if (binary_search(arr.begin(), arr.end(), y))
                {
                    return 1;
                }
            }
        }

        return -1;
    }
};

// link : https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1