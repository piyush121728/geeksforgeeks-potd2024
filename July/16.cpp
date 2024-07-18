#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printString(string s, char ch, int count)
    {
        // Your code goes here
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            count -= (s[i] == ch);
            if (count == 0)
            {
                return s.substr(i + 1);
            }
        }

        return "";
    }
};

// link : https://www.geeksforgeeks.org/problems/remaining-string3515/1