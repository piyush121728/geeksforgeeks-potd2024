#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    bool rec(Node *root, int target, vector<int> &ans)
    {
        if (!root)
        {
            return false;
        }

        if (root->data == target)
        {
            return true;
        }

        ans.push_back(root->data);
        if (rec(root->left, target, ans))
        {
            return true;
        }

        if (rec(root->right, target, ans))
        {
            return true;
        }
        ans.pop_back();
        return false;
    }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
        // Code here
        vector<int> ans;
        rec(root, target, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1