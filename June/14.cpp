#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string armstrongNumber(int num)
    {
        // code here
        int m = 0;
        int n = num;
        while (n > 0)
        {
            int d = n % 10;
            m += pow(d, 3);
            n /= 10;
        }

        if (m != num)
        {
            return "false";
        }

        return "true";
    }
};

// link :https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1