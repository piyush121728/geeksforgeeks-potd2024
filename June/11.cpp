#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b)
    {
        // code here
        vector<pair<int, int>> v;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            v.push_back({abs(a[i] - b[i]), i});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        for (int i = 0; i < n; i++)
        {
            int j = v[i].second;
            if (x > 0 && y > 0)
            {
                if (a[j] >= b[j])
                {
                    res += a[j];
                    x--;
                }
                else
                {
                    res += b[j];
                    y--;
                }
            }
            else if (x == 0)
            {
                res += b[j];
                y--;
            }
            else if (y == 0)
            {
                res += a[j];
                x--;
            }
        }

        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1