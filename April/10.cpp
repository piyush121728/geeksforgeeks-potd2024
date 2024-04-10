#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSingle(int n, int arr[])
    {
        // code here
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x ^= arr[i];
        }
        return x;
    }
};

// link : https://www.geeksforgeeks.org/problems/alone-in-couple5507/1