#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRow(int n, int m, vector<vector<int>> a)
    {
        // code here
        int mini = INT_MAX;
        int r = -1;
        for(int i = 0; i < n; i++){
            int sum = accumulate(a[i].begin(), a[i].end(), 0);
            if(sum<mini){
                mini = sum;
                r = i; 
            }
        }

        return -1;
    }
};

// link : https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1