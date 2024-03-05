#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swapElements(int arr[], int n)
    {
        for(int i = 0; i < n-2; i++){
            swap(arr[i],arr[i+2]);
        }
        
    }
};

// link : https://www.geeksforgeeks.org/problems/need-some-change/1