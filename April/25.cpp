#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxSum(int n, int m, vector<vector<int>> mat)
    {
        // code here
        if (n <= 2 || m <= 2)
        {
            return -1;
        }
        int res = INT_MIN;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                int sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + 1] + mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
                res = max(sum, res);
            }
        }

        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1