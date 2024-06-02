#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> ans;
        ans.push_back(0);
        int temp = 0;

        for (int i = 0; i < q; i++)
        {
            if (queries[i][0] == 0)
            {
                ans.push_back(temp ^ queries[i][1]);
            }
            else if (queries[i][0] == 1)
            {
                temp = temp ^ queries[i][1];
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = ans[i] ^ temp;
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};