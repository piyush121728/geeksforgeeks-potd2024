#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCoverage(vector<vector<int>> &mat)
    {
        // Code here
        int cnt = 0, n = mat.size(), m = mat[0].size();
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout<<mat[i][j]<<endl;
                if (mat[i][j] == 0)
                {
                    // cout<<mat[i][j]<<" "<<i<<" "<<j<<endl;
                    for (int k = 0; k < 4; k++)
                    {
                        int newR = i + dir[k][0];
                        int newC = j + dir[k][1];

                        if (newR >= 0 && newR < n && newC >= 0 && newC < m && mat[newR][newC] == 1)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

// link : https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1