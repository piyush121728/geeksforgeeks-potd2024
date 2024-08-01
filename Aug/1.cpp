#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {
        // code here
        int startingRow = 0;
        int endingRow = matrix.size() - 1;
        int startingCol = 0;
        int endingCol = matrix[0].size() - 1;
        vector<int> ans;
        int total = matrix.size() * matrix[0].size();
        int count = 0;
        while (count < total)
        {
            // starting row
            for (int i = startingCol; i <= endingCol && count < total; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            // ending column
            for (int i = startingRow; i <= endingRow && count < total; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // ending row
            for (int i = endingCol; i >= startingCol && count < total; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // starting column
            for (int i = endingRow; i >= startingRow && count < total; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1