#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int n, int m)
    {
        // Your code here
        set<vector<int>> st;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (st.count(matrix[i]) > 0)
            {
                v.push_back(i);
            }
            else
            {
                st.insert(matrix[i]);
            }
        }

        return v;
    }
};

// link : https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1