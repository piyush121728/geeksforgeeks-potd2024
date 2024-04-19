#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        // Your code here
        vector<int> freq(n + 1, 0);
        vector<int> v;
        for (int i = 0; i < n + 2; i++)
        {
            freq[arr[i]]++;
            if (freq[arr[i]] == 2)
            {
                v.push_back(arr[i]);
            }
        }
        return v;
    }
};

// link : https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1