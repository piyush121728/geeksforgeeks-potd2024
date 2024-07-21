#include<bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long long int findMaxProduct(vector<int> &arr)
    {
        // Write your code here
        int mod = 1000000007, n = arr.size(), maxi = INT_MIN, cntNeg = 0, cntPos = 0;
        long long int sum = 1;
        if (n == 1)
        {
            return arr[0];
        }
        if (n == 2)
        {
            if ((arr[0] == 0 && arr[1] < 0) || (arr[0] < 0 && arr[1] == 0))
            {
                return 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                maxi = max(maxi, arr[i]);
            }
            cntPos += (arr[i] > 0);
            cntNeg += (arr[i] < 0);
        }

        if (cntPos == 0 && cntNeg == 0)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }
            if (arr[i] < 0 && arr[i] == maxi && cntNeg % 2 == 1)
            {
                cntNeg--;
                continue;
            }
            // cout<<arr[i]<<" ";
            sum = (sum % mod * arr[i] % mod) % mod;
        }
        // cout<<endl;
        return sum;
    }
};

// link : https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1