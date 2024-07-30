#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        // code here
        int n = arr.size(), m = arr[0].size();
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

// link : https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1