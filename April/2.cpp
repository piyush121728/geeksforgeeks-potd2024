#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int absolute_diff(Node *root)
    {
        // Your code here
        vector<int> v;
        inorder(root, v);
        int diff = INT_MAX;
        for (int i = 1; i < v.size(); i++)
        {
            diff = min(diff, abs(v[i - 1] - v[i]));
        }
        return diff;
    }
};

// link : https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1