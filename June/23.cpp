#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        // Your code goes here
        stack<int> st;
        int n = str.size(), j = 1;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                st.push(j);
                res.push_back(j);
                j++;
            }
            else if (str[i] == ')')
            {
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/print-bracket-number4058/1