#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    Node *lca(Node *root, int a, int b)
    {
        if (!root || root->data == a || root->data == b)
        {
            return root;
        }

        Node *left = lca(root->left, a, b);
        Node *right = lca(root->right, a, b);

        if (!left)
        {
            return right;
        }
        else if (!right)
        {
            return left;
        }
        return root;
    }

    int dist(Node *root, int data)
    {
        if (!root)
        {
            return 1e8;
        }
        if (root->data == data)
        {
            return 0;
        }

        int left = dist(root->left, data) + 1;
        int right = dist(root->right, data) + 1;

        return min(left, right);
    }

    int findDist(Node *root, int a, int b)
    {
        // Your code here
        Node *lCA = lca(root, a, b);
        // cout<<lCA->data<<endl;
        return dist(root, a) + dist(root, b) - 2 * dist(root, lCA->data);
    }
};

// link : https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1