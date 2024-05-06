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

void traverse(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    if (root->left && !root->right)
    {
        ans.push_back(root->left->data);
        traverse(root->left, ans);
    }
    else if (root->right && !root->left)
    {
        ans.push_back(root->right->data);
        traverse(root->right, ans);
    }
    else
    {
        traverse(root->left, ans);
        traverse(root->right, ans);
    }
}

vector<int> noSibling(Node *node)
{
    // code here
    vector<int> ans;
    traverse(node, ans);
    if (ans.size() == 0)
    {
        return {-1};
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// link: https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1