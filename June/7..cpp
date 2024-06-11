#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   
    int maxOccured(int n, int l[], int r[], int maxx)
    {

        // Your code here
        int count[maxx + 2] = {0};
        for (int i = 0; i < n; i++)
        {
            count[l[i]]++;
            count[r[i] + 1]--;
        }
        for (int i = 1; i < maxx + 2; i++)
        {
            count[i] += count[i - 1];
        }
        int maxi = 0;
        int indx = -1;
        for (int i = 0; i < maxx + 2; i++)
        {
            if (count[i] > maxi)
            {
                maxi = count[i];
                indx = i;
            }
        }

        return indx;
    }
};

// link : https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1