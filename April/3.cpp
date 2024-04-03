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
    Node *lowestCommonAncestor(Node *root, int p, int q)
    {
        if (!root)
        {
            return nullptr;
        }

        if (root->data == p || root->data == q)
        {
            return root;
        }

        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);

        if (left && !right)
        {
            return left;
        }
        else if (!left && right)
        {
            return right;
        }
        else if (left && right)
        {
            return root;
        }

        return nullptr;
    }

    vector<int> ancestors;

    void findAncestors(Node *root, Node *lca)
    {

        while (root)
        {
            ancestors.push_back(root->data);
            if (root->data == lca->data)
            {
                return;
            }

            if (root->data > lca->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }

    int kthCommonAncestor(Node *root, int k, int x, int y)
    {
        ancestors.clear();
        Node *lca = lowestCommonAncestor(root, x, y);
        findAncestors(root, lca);
        int n = ancestors.size();
        if (n - k < 0)
        {
            return -1;
        }

        return ancestors[n - k];
    }
};

// link : https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1