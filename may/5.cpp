#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        // add code here.
        map<int, int> mp;
        queue<pair<Node *, int>> pn;
        pn.push({root, 0});

        while (!pn.empty())
        {
            auto node = pn.front();
            pn.pop();
            mp[node.second] += node.first->data;

            if (node.first->left)
            {
                pn.push({node.first->left, node.second - 1});
            }
            if (node.first->right)
            {
                pn.push({node.first->right, node.second - 1});
            }
        }

        vector<int> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        mp.clear();

        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/vertical-sum/1