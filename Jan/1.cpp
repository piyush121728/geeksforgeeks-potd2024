#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        int n = nums.size();
        map<int, int> mp;

        for (auto n : nums)
        {
            mp[n % k]++;
        }
        for (auto it : mp)
        {
            int find = k - (it.first % k);
            if (it.first % k == 0 && mp[it.first % k] % 2 == 0)
            {
                continue;
            }
            if (mp[find] != mp[it.first % k])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1