#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearch(int n, vector<int> &b, int x)
    {
        int i = 0, j = n - 1;

        int indi = -1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (b[mid] > x)
            {
                j = mid - 1;
            }
            else
            {
                indi = max(mid, i);
                i = mid + 1;
            }
        }
        return indi;
    }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &q, int m)
    {
        // Your code goes here;
        sort(b.begin(), b.end());
        vector<int> ans;
        for (auto x : q)
        {

            ans.push_back(binarySearch(n, b, a[x]) + 1);
        }
        return ans;
    }
};

// link :https://www.geeksforgeeks.org/problems/count-the-elements1529/1
