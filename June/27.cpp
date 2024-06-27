#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size(), m = mat[0].size();
    for (int r = 0; r < n; r++)
    {
        int i = r;
        int j = 0;
        int val = mat[i][j];
        while (i < n && j < m)
        {
            if (mat[i][j] != val)
            {
                return false;
            }
            i++;
            j++;
        }
    }
    for (int c = 0; c < m; c++)
    {
        int j = c;
        int i = 0;
        int val = mat[i][j];
        while (i < n && j < m)
        {
            if (mat[i][j] != val)
            {
                return false;
            }
            i++;
            j++;
        }
    }
    return true;
}

// link : https://www.geeksforgeeks.org/problems/toeplitz-matrix/1