#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    int rec(Node *root, bool &res)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return 0;
        }

        int left = rec(root->left, res);
        int right = rec(root->right, res);
        if (root->left)
        {
            left += root->left->data;
        }
        if (root->right)
        {
            right += root->right->data;
        }

        if (root->data != left + right)
        {
            res = 0;
        }

        // cout<<root->data<<" "<<left<<" "<<right<<endl;

        return left + right;
    }
    bool isSumTree(Node *root)
    {
        // Your code here
        bool res = 1;
        rec(root, res);
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/sum-tree/1