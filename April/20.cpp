#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Your code here
        // return vector with correct order of elements
        set<int> st;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            st.insert(arr1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            st.insert(arr2[i]);
        }

        for (auto x : st)
        {
            v.push_back(x);
        }

        st.clear();
        return v;
    }
};

// link : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1