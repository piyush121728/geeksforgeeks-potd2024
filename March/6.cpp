#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        // code here.
        vector<int> v;
        int n = pattern.size();
        for (int i = 0; i <= text.size() - n; i++)
        {
            if (text.substr(i, n) == pattern)
            {
                v.push_back(i + 1);
            }
        }

        return v;
    }
};
// link : https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1