#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long ExtractNumber(string s)
    {
        s += ' ';
        long long ans = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                string p = "";
                bool fg = 1;
                while (i < s.size() and s[i] != ' ')
                {
                    if (s[i] == '9')
                    {
                        fg = 0;
                    }
                    p += s[i++];
                }
                if (fg)
                {
                    ans = max(ans, stoll(p));
                }
            }
        }
        return ans;
    }
};



// link :https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1