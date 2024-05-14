#include <bits/stdc++.h>
using namespace std;

// TLE
/*
class Solution
{
public:
    vector<vector<int>> v;
    void rec(int i, int k, vector<int> arr, int n, vector<int> temp)
    {
        if (i >= n)
        {
            if (k == 0)
            {
                v.push_back(temp);
            }
            return;
        }

        // not take
        rec(i + 1, k, arr, n, temp);
        // take
        if (arr[i] <= k)
        {
            temp.push_back(arr[i]);
            rec(i + 1, k - arr[i], arr, n, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        // code here
        v.clear();
        vector<int> temp;
        sort(arr.begin(), arr.end());
        rec(0, k, arr, n, temp);
        sort(v.begin(), v.end());
        return v;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> v;
    void rec(int i, int k, vector<int> arr, int n, vector<int> temp)
    {
        if (k == 0)
        {
            v.push_back(temp);
            return;
        }
        if (i >= n)
        {
            return;
        }

        for (int j = i; j < n; j++)
        {
            if (j != i && arr[j] == arr[j - 1])
            {
                continue;
            }
            if (arr[j] <= k)
            {
                temp.push_back(arr[j]);
                rec(j + 1, k - arr[j], arr, n, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        // code here
        v.clear();
        vector<int> temp;
        sort(arr.begin(), arr.end());
        rec(0, k, arr, n, temp);
        return v;
    }
};

// link : https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1