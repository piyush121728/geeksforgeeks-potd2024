#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mat[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    long long rec(int i, int j, int n, vector<vector<long long>> &dp)
    {
        if (n == 1)
        {
            return 1;
        }

        if (dp[mat[i][j]][n] != -1)
        {
            return dp[mat[i][j]][n];
        }

        long long res = 0;

        for (int d = 0; d < 5; d++)
        {
            int x = dir[d][0] + i, y = dir[d][1] + j;

            if (x >= 0 && x < 4 && y >= 0 && y < 3 && mat[x][y] != -1)
            {
                res = res + rec(x, y, n - 1, dp);
            }
        }

        return dp[mat[i][j]][n] = res;
    }

    long long getCount(int n)
    {
        // Your code goes here
        vector<vector<long long>> dp(10, vector<long long>(n + 1, -1));
        long long cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] != -1)
                {
                    long long res = rec(i, j, n, dp);
                    cnt += res;
                }
            }
        }
        return cnt;
    }
};
// link : https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1