#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddEven(string s)
    {
        // code here
        vector<int> freq(26);
        for (auto i : s)
            freq[i - 'a']++;

        int c = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                if ((i + 1) % 2 == freq[i] % 2)
                    c++;
            }
        }
        if (c & 1)
            return "ODD";
        return "EVEN";
    }
};

// link : https://www.geeksforgeeks.org/problems/help-nobita0532/1