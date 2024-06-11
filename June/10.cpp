#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        // code here
        char arr[9] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        set<char> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nuts[i]);
        }
        int i = 0;
        for (int j = 0; j < 9; j++)
        {
            if (st.count(arr[j]) > 0)
            {
                nuts[i] = arr[j];
                bolts[i] = arr[j];
                i++;
            }
        }
    }
};

// link : https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1