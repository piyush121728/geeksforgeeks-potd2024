#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countNumberswith4(int n)
    {
        // code here
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            string str = to_string(i);
            for (auto x : str)
            {
                if (x == '4')
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1