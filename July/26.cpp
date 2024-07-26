#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kPangram(string str, int k)
    {
        // code here
        unordered_map<char, int> mp;
        int cnt = 1;
        for (auto ch : str)
        {
            if (ch != ' ')
            {
                mp[ch]++;
                if (mp[ch] > 1)
                {
                    cnt++;
                }
            }
        }

        if (mp.size() == 26)
        {
            return true;
        }
        else if (26 - mp.size() <= cnt && 26 - mp.size() <= k)
        {
            return true;
        }
        return false;
    }
};

// link : https://www.geeksforgeeks.org/problems/k-pangrams0909/1