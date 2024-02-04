#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string s)
    {
        // Your code here
        int n = s.size();
        int num = 0;
        bool neg = (s[0] == '-');
        for (int i = (neg) ? 1 : 0; i < n; i++)
        {
            if(s[i]<'0' || s[i]>'9')
            {
                return -1;
            }

            num = (num*10) + (s[i]-'0');
        }
        return (neg) ? (-1)*num : num;
    }
};