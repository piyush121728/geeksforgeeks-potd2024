#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        // code here
        int cnt = 0;
        for (int l = 1; l <= 2 * r; l++)
        {
            for (int w = 1; w <= 2 * r; w++)
            {
                if ((l * l) + (w * w) <= (4 * r * r))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// link : https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1