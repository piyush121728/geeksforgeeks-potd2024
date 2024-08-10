#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Maximize(vector<int> &arr)
    {
        // Complete the function
        sort(arr.begin(), arr.end());
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += ((long long)arr[i] * i) % 1000000007;
            sum %= 1000000007;
        }

        return sum;
    }
};
// link : https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1