#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        // code here.
        string str = "1";
        int n = s.size();
        int i = 0;
        for (; i < n; i++)
        {
            if (s[i] == '1')
            {
                s = s.substr(i);
                break;
            }
        }
        if (i == n)
        {
            s = "0";
        }
        n = s.size();

        if (s[n - 1] == '0')
        {
            s[n - 1] = '1';
            return s;
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                    return s;
                }
                s[i] = '0';
            }
        }

        str += s;
        return str;
    }
};

// link : https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1