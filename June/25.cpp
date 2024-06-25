#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat)
    {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res[i][j] = mat[i][(j + k) % m];
            }
        }

        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1