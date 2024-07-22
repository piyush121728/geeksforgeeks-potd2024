#include <bits/stdc++.h>
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
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    bool isValidBST(Node *root, int minVal, int maxVal, int &size)
    {
        if (root == NULL)
            return true;
        if (root->data >= maxVal || root->data <= minVal)
        {
            return false;
        }
        size++;
        bool l = isValidBST(root->left, minVal, root->data, size);
        bool r = isValidBST(root->right, root->data, maxVal, size);

        return l && r;
    }

    void helper(Node *root, int &maxi)
    {
        if (!root)
        {
            return;
        }

        int size = 0;
        if (isValidBST(root, INT_MIN, INT_MAX, size))
        {
            maxi = max(maxi, size);
        }

        helper(root->left, maxi);
        helper(root->right, maxi);
    }

    int largestBst(Node *root)
    {
        // Your code here
        int maxi = 0;
        helper(root, maxi);
        return maxi;
    }
};