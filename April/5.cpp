#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int min_operations(vector<int> &nums)
    {
        // Code here
        int n = nums.size();
        // Here we have to do co-ordinate shifting to handle the prev as -1
        // After co-ordinate shifting -1 becomes 0 , 0 becomes 1 and so on.
        vector<int> ahead(n + 1, 0), curr(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int notTake = ahead[j + 1];
                int take = 0;
                if (j == -1 || (nums[i] > nums[j] && nums[i] - nums[j] >= i - j))
                {
                    take = 1 + ahead[i + 1];
                }

                curr[j + 1] = max(take, notTake);
            }
            ahead = curr;
        }
        return n - ahead[0];
    }
};

// link : https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1