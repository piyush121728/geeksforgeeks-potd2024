#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool helper(Node *root, int mini, int maxi)
    {
        if (!root)
        {
            return true;
        }

        if (root->data <= mini || root->data >= maxi)
        {
            return false;
        }

        return helper(root->left, mini, root->data) && helper(root->right, root->data, maxi);
    }
    bool isBST(Node *root)
    {
        // Your code here
        return helper(root, INT_MIN, INT_MAX);
    }
};

//link :  https://www.geeksforgeeks.org/problems/check-for-bst/1