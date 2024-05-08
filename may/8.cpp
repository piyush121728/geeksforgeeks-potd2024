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
    vector<vector<int>> path;
    void rec(Node *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }

        v.push_back(root->data);
        if (!root->left && !root->right)
        {
            path.push_back(v);
        }
        rec(root->left, v);
        rec(root->right, v);
        v.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        // code here

        vector<int> v;
        rec(root, v);
        return path;
    }
};

// link : https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1