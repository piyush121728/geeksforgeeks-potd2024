#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        // Your code goes here
        set<int> st;
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            st.insert(b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (st.count(a[i]) == 0)
            {
                v.push_back(a[i]);
            }
        }
        return v;
    }
};
// link : https://www.geeksforgeeks.org/problems/in-first-but-second5423/1