#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pattern(vector<vector<int>> &arr)
    {
        // Code Here
        int n = arr.size(), m = arr[0].size();
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = m - 1;
            while (l < r)
            {
                if (arr[i][l] != arr[i][r])
                {
                    break;
                }
                l++;
                r--;
            }
            if (l >= r)
            {
                return to_string(i) + " " + 'R';
            }
        }
        for (int i = 0; i < m; i++)
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                if (arr[l][i] != arr[r][i])
                {
                    break;
                }
                l++;
                r--;
            }
            if (l >= r)
            {
                return to_string(i) + " " + 'C';
            }
        }

        return "-1";
    }
};

// link : https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1